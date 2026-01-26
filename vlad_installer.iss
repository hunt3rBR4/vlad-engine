; Vlad Engine - Installer Script
; Built for Sovereignty

#define AppName "Vlad Engine"
#define AppVersion "1.0.0"
#define AppPublisher "Vlad Community"
#define AppURL "https://github.com/vlad-engine"
#define AppExeName "vlad.windows.editor.x86_64.exe"

[Setup]
AppId={{6B5F4D3C-2A1E-4E9D-80D7-1C2B3A4F5E6D}
AppName={#AppName}
AppVersion={#AppVersion}
AppPublisher={#AppPublisher}
AppPublisherURL={#AppURL}
AppSupportURL={#AppURL}
AppUpdatesURL={#AppURL}
DefaultDirName={autopf}\{#AppName}
DisableProgramGroupPage=yes
LicenseFile=LICENSE.txt
; Setup Icon
; SetupIconFile=godot-master\godot-master\platform\windows\godot.ico
OutputDir=installer_output
OutputBaseFilename=VladEngine_Setup
Compression=lzma
SolidCompression=yes
WizardStyle=modern
; Branding Images
WizardImageFile=vlad_wizard.png
WizardSmallImageFile=vlad_header.png

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "brazilianportuguese"; MessagesFile: "compiler:Languages\BrazilianPortuguese.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "godot-master\godot-master\bin\{#AppExeName}"; DestDir: "{app}"; Flags: ignoreversion
; Add export templates and other files if needed
; Source: "c:\Users\Sr Ozana\Desktop\ValdNostr\godot-master\godot-master\bin\*.zip"; DestDir: "{app}\templates"; Flags: ignoreversion recursesubdirs createallsubdirs

[Icons]
Name: "{autoprograms}\{#AppName}"; Filename: "{app}\{#AppExeName}"
Name: "{autodesktop}\{#AppName}"; Filename: "{app}\{#AppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#AppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(AppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent
