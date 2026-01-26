/**************************************************************************/
/*  nostr_client.cpp                                                      */
/**************************************************************************/

#include "nostr_client.h"

#include "core/io/json.h"
#include "core/string/print_string.h"
#include "core/variant/array.h"
#include "core/variant/dictionary.h"
#include "core/variant/variant.h"

void NostrClient::_bind_methods() {
	ClassDB::bind_method(D_METHOD("connect_to_relay", "url"), &NostrClient::connect_to_relay);
	ClassDB::bind_method(D_METHOD("poll"), &NostrClient::poll);
	ClassDB::bind_method(D_METHOD("send_event", "event"), &NostrClient::send_event);
	ClassDB::bind_method(D_METHOD("subscribe", "filters"), &NostrClient::subscribe);
	ClassDB::bind_method(D_METHOD("verify_nip05", "identifier"), &NostrClient::verify_nip05);
	ClassDB::bind_method(D_METHOD("zap_user", "pubkey", "amount", "comment"), &NostrClient::zap_user, DEFVAL(""));

	ADD_SIGNAL(MethodInfo("event_received", PropertyInfo(Variant::DICTIONARY, "event")));
	ADD_SIGNAL(MethodInfo("connected"));
	ADD_SIGNAL(MethodInfo("disconnected"));
}

void NostrClient::subscribe(const Array &p_filters) {
	if (peer.is_null() || peer->get_ready_state() != WebSocketPeer::STATE_OPEN) {
		return;
	}

	Array msg;
	msg.push_back("REQ");
	msg.push_back("subscription_id"); // Deveria ser dinâmico
	for (int i = 0; i < p_filters.size(); i++) {
		msg.push_back(p_filters[i]);
	}

	String json_str = JSON::stringify(msg);
	peer->send_text(json_str);
}

Error NostrClient::connect_to_relay(const String &p_url) {
	relay_url = p_url;
	peer = Ref<WebSocketPeer>(WebSocketPeer::create());
	return peer->connect_to_url(relay_url);
}

void NostrClient::poll() {
	if (peer.is_null()) {
		return;
	}

	peer->poll();
	WebSocketPeer::State state = peer->get_ready_state();

	if (state == WebSocketPeer::STATE_OPEN) {
		while (peer->get_available_packet_count() > 0) {
			PackedByteArray packet;
			Error err = peer->get_packet_buffer(packet);
			if (err == OK) {
				String msg;
				msg.parse_utf8((const char *)packet.ptr(), packet.size());

				JSON json;
				if (json.parse(msg) == OK) {
					Variant v = json.get_data();
					if (v.get_type() == Variant::ARRAY) {
						Array arr = v;
						if (arr.size() >= 3 && arr[0].operator String() == "EVENT") {
							Dictionary event = arr[2];
							emit_signal("event_received", event);
							print_line("VladNostr: Event received and emitted via Signal.");
						} else if (arr.size() > 0 && arr[0].operator String() == "OK") {
							print_line("VladNostr: Relay accepted event (OK).");
						}
					}
				}
			}
		}
	} else if (state == WebSocketPeer::STATE_CLOSED) {
		// print_line("VladNostr: Connection closed.");
	}
}

void NostrClient::send_event(const Dictionary &p_event) {
	if (peer.is_null() || peer->get_ready_state() != WebSocketPeer::STATE_OPEN) {
		return;
	}

	Array msg;
	msg.push_back("EVENT");
	msg.push_back(p_event);

	String json_str = JSON::stringify(msg);
	Vector<uint8_t> packet;
	packet.resize(json_str.utf8().length());
	memcpy(packet.ptrw(), json_str.utf8().get_data(), packet.size());

	peer->send_binary(packet);
}

void NostrClient::verify_nip05(const String &p_identifier) {
	// NIP-05: Realiza um fetch HTTPS para /.well-known/nostr.json?name=...
	print_line("VladNostr: Initiating NIP-05 verification for " + p_identifier);
	// Aqui usaríamos o HTTPClient do Godot para validar o mapeamento identifier -> pubkey
}

void NostrClient::zap_user(const String &p_pubkey, uint64_t p_amount, const String &p_comment) {
	// NIP-57: Gera um Zap Request (Kind 9734)
	print_line("VladNostr: Creating Zap Request for " + p_pubkey + " Amount: " + String::num_uint64(p_amount));
}

NostrClient::NostrClient() {
}
