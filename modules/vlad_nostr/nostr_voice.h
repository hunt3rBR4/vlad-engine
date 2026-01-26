#ifndef NOSTR_VOICE_H
#define NOSTR_VOICE_H

#include "core/object/ref_counted.h"
#include "modules/webrtc/webrtc_peer_connection.h"

class NostrVoice : public RefCounted {
	GDCLASS(NostrVoice, RefCounted);

	Ref<WebRTCPeerConnection> peer_connection;
	PackedByteArray shared_secret;

protected:
	static void _bind_methods();

public:
	void initialize_voice(const PackedByteArray &p_secret);
	void process_audio_frame(PackedByteArray &p_frame); // Camada de Segurança Militar

	NostrVoice();
};

#endif // NOSTR_VOICE_H
