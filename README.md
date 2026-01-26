# Vlad Engine

## 2D and 3D Cross-Platform Game Engine

**Vlad Engine is a sovereign, Nostr-native fork of Godot Engine 4.6** — a feature-packed, cross-platform game engine to create 2D and 3D games with complete freedom and ownership.

Built on the solid foundation of Godot, Vlad extends it with:
- **Nostr Protocol Integration**: Native support for decentralized identity, multiplayer, and monetization
- **Zero Gatekeepers**: No telemetry, no centralized asset stores, no masters
- **Sovereign by Design**: Your games, your data, your freedom

Games can be exported with one click to all major platforms: Linux, macOS, Windows, Android, iOS, and Web.

---

## Free, Open Source, and Truly Sovereign

Vlad Engine is completely free and open source under the **MIT license**. No strings attached, no royalties, nothing. Your games are yours, down to the last line of code.

This is a **libertarian fork** focused on:
- **Individual sovereignty** and self-ownership
- **Voluntary exchange** and free markets (Lightning/Nostr zaps)
- **Privacy** and cryptographic identity
- **Decentralization** over institutional gatekeeping

### Heritage & Acknowledgment

Vlad Engine is proudly based on [Godot Engine](https://godotengine.org), originally developed by Juan Linietsky and Ariel Manzur, and maintained by an incredible open-source community since 2014. We stand on the shoulders of giants.

All credit to the original Godot contributors — this fork extends their work with Nostr sovereignty and removes centralized dependencies.

---

## Getting Started

### Binary Downloads

**TODO**: Official Vlad binaries will be available at:
- **Website**: `https://YOUR-WEBSITE-HERE.com/download`

For now, compile from source (see below).

### Compiling from Source

Vlad Engine uses the same build system as Godot (SCons).

**Requirements**:
- Python 3.6+
- SCons 4.0+
- Platform-specific compilers (see [Godot compilation docs](https://docs.godotengine.org/en/latest/contributing/development/compiling/))

**Basic compilation** (Windows example):
```bash
cd godot-master
scons platform=windows target=editor
```

For optimized builds and export templates, see our custom build configurations in `custom.py` (coming soon).

---

## Nostr Integration

Vlad Engine includes **native Nostr protocol support** via Rust GDExtension:

- **VladIdentity**: Manage nsec/npub keys, sign events cryptographically
- **VladNostr**: Connect to relays, subscribe to events, publish notes
- **Zaps (NIP-57)**: Monetize your games with Lightning Network payments
- **Decentralized Multiplayer**: Matchmaking and signaling over Nostr
- **Asset Distribution**: Load mods and assets from Nostr events (NIP-23/63)

Full documentation coming in `v0.1-beta`.

---

## Community

Vlad is a **community-driven sovereign project**. We believe in voluntary association and free collaboration.

- **Website**: `https://YOUR-WEBSITE-HERE.com` *(TODO: Add your site)*
- **Nostr**: `npub1YOUR-PUBKEY-HERE` *(TODO: Add your Nostr pubkey)*
- **GitHub**: This repository

For Godot-specific resources, the [Godot documentation](https://docs.godotengine.org) remains highly relevant for non-Nostr features.

---

## Contributing

Contributions are welcome! If you believe in sovereignty, privacy, and decentralization, you're in the right place.

Please see [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines (inherited from Godot, will be updated for Vlad-specific features).

---

## Philosophy

> "The engine belongs to the user, not the platform."

Vlad Engine rejects:
- ❌ Centralized asset stores
- ❌ Telemetry and data collection
- ❌ Mandatory account creation
- ❌ Gatekeeping and censorship
- ❌ DRM and artificial restrictions

Vlad Engine embraces:
- ✅ Cryptographic identity (Nostr)
- ✅ Peer-to-peer collaboration
- ✅ Sound money (Bitcoin/Lightning)
- ✅ Privacy by default
- ✅ User sovereignty

---

## License

Vlad Engine is licensed under the **MIT License**, same as Godot.

See [LICENSE.txt](LICENSE.txt) for details.

---

**Made with freedom. Built for sovereignty. Powered by Nostr.**
