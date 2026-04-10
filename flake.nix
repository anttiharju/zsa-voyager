{
  description = "ZSA Voyager keymap build environment";
  inputs = {
    nixpkgs-unstable.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  };
  outputs =
    { self, nixpkgs-unstable }:
    let
      systems = [
        "aarch64-darwin"
        "x86_64-darwin"
        "x86_64-linux"
        "aarch64-linux"
      ];
      forAllSystems =
        f: nixpkgs-unstable.lib.genAttrs systems (system: f (nixpkgs-unstable.legacyPackages.${system}));
    in
    {
      devShells = forAllSystems (pkgs: {
        default = pkgs.mkShell {
          packages = [
            pkgs.qmk
            pkgs.dos2unix
          ];
        };
      });
    };
}
