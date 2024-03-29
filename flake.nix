{
  description = "Shikanime's algorithms sketchbook";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs";
    devenv = {
      url = "github:cachix/devenv";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  nixConfig = {
    extra-public-keys = [
      "shikanime.cachix.org-1:OrpjVTH6RzYf2R97IqcTWdLRejF6+XbpFNNZJxKG8Ts="
      "devenv.cachix.org-1:w1cLUi8dv3hnoSPGAuibQv+f9TZLr6cv/Hm9XgU50cw="
    ];
    extra-substituters = [
      "https://shikanime.cachix.org"
      "https://devenv.cachix.org"
    ];
  };

  outputs = { nixpkgs, devenv, ... }@inputs:
    let
      systems = [
        "aarch64-linux"
        "x86_64-linux"
      ];
    in
    {
      devShells = nixpkgs.lib.genAttrs systems (system:
        let pkgs = import nixpkgs { inherit system; }; in {
          default = devenv.lib.mkShell {
            inherit inputs pkgs;
            modules = [
              ./nix/base.nix
              ./nix/beam.nix
              ./nix/cc.nix
              ./nix/javascript.nix
              ./nix/ocaml.nix
              ./nix/python.nix
            ];
          };
        }
      );
    };
}
