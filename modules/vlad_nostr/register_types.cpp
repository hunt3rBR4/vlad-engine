/**************************************************************************/
/*  register_types.cpp                                                    */
/**************************************************************************/

#include "register_types.h"

#include "core/object/class_db.h"
#include "nostr_client.h"
#include "nostr_identity.h"
#include "nostr_voice.h"

void initialize_vlad_nostr_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	GDREGISTER_CLASS(NostrIdentity);
	GDREGISTER_CLASS(NostrClient);
	GDREGISTER_CLASS(NostrVoice);
}

void uninitialize_vlad_nostr_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}
