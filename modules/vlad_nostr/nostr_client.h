/**************************************************************************/
/*  nostr_client.h                                                        */
/**************************************************************************/

#ifndef NOSTR_CLIENT_H
#define NOSTR_CLIENT_H

#include "core/object/class_db.h"
#include "core/object/ref_counted.h"
#include "core/variant/dictionary.h"
#include "core/variant/variant.h"
#include "modules/websocket/websocket_peer.h"

class NostrClient : public RefCounted {
	GDCLASS(NostrClient, RefCounted);

	Ref<WebSocketPeer> peer;
	String relay_url;

protected:
	static void _bind_methods();

public:
	Error connect_to_relay(const String &p_url);
	void poll();
	void send_event(const Dictionary &p_event);
	void subscribe(const Array &p_filters);
	void verify_nip05(const String &p_identifier);
	void zap_user(const String &p_pubkey, uint64_t p_amount, const String &p_comment = "");

	NostrClient();
};

#endif // NOSTR_CLIENT_H
