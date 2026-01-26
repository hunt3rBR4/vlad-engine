/**************************************************************************/
/*  nostr_identity.h                                                      */
/**************************************************************************/

#ifndef NOSTR_IDENTITY_H
#define NOSTR_IDENTITY_H

#include "core/object/class_db.h"
#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "core/variant/dictionary.h"
#include "core/variant/variant.h"

class NostrIdentity : public RefCounted {
	GDCLASS(NostrIdentity, RefCounted);

	String private_key; // Hex nsec
	String public_key; // Hex npub

protected:
	static void _bind_methods();

public:
	String generate_key_pair();
	String get_public_key() const;
	String get_private_key() const;
	String get_npub() const;
	String get_nsec() const;
	void set_private_key(const String &p_key);

	String calculate_event_id(const Dictionary &p_event);
	String sign_event(const String &p_event_id_hex);

	String encrypt_message(const String &p_recipient_pubkey, const String &p_plaintext);
	String decrypt_message(const String &p_sender_pubkey, const String &p_encrypted_data);

	// NIP-33 & NIP-78: Persistence
	Dictionary create_replaceable_event(int p_kind, const String &p_identifier, const String &p_content, const Array &p_tags = Array());
	Dictionary create_app_storage_event(const String &p_key, const String &p_content);
	Dictionary create_game_save_event(const String &p_game_id, const String &p_save_data);

	// NIP-94: File Metadata (Assets/Mods)
	Dictionary create_file_metadata_event(const String &p_url, const String &p_sha256, uint64_t p_size, const String &p_alt = "");

	NostrIdentity();
};

#endif // NOSTR_IDENTITY_H
