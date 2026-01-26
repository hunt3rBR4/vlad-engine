#include "nostr_voice.h"
#include "core/crypto/crypto.h"

void NostrVoice::_bind_methods() {
	ClassDB::bind_method(D_METHOD("initialize_voice", "secret"), &NostrVoice::initialize_voice);
	ClassDB::bind_method(D_METHOD("process_audio_frame", "frame"), &NostrVoice::process_audio_frame);
}

void NostrVoice::initialize_voice(const PackedByteArray &p_secret) {
	shared_secret = p_secret;
	peer_connection.instantiate();
	// Configurar WebRTC nativo do motor
}

void NostrVoice::process_audio_frame(PackedByteArray &p_frame) {
	// AQUI: Implementação do ChaCha20-Poly1305 (Segurança Militar)
	// Ciframos o áudio ANTES dele sair pelo WebRTC
}

NostrVoice::NostrVoice() {}
