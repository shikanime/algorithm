{
  inputs = {
    devenv.url = "github:cachix/devenv";
    flake-parts.url = "github:hercules-ci/flake-parts";
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
    treefmt-nix.url = "github:numtide/treefmt-nix";
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

  outputs =
    inputs@{
      devenv,
      flake-parts,
      treefmt-nix,
      ...
    }:
    flake-parts.lib.mkFlake { inherit inputs; } {
      imports = [
        devenv.flakeModule
        treefmt-nix.flakeModule
      ];
      perSystem = _: {
        treefmt = {
          projectRootFile = "flake.nix";
          enableDefaultExcludes = true;
          programs = {
            clang-format.enable = true;
            cmake-format.enable = true;
            mix-format.enable = true;
            nixfmt.enable = true;
            ocamlformat.enable = true;
            prettier.enable = true;
            ruff-format.enable = true;
            shfmt.enable = true;
            statix.enable = true;
            taplo.enable = true;
          };
          settings.global.excludes = [
            "*.jinja2"
            "*.python-version"
            "algorithm-beam/priv/*"
            "algorithm-cc/share/*"
            "LICENSE"
          ];
        };
        devenv.shells = {
          default.imports = [
            ./nix/modules/devenv/base.nix
          ];
          beam.imports = [
            ./nix/modules/devenv/base.nix
            ./nix/modules/devenv/beam.nix
          ];
          cc.imports = [
            ./nix/modules/devenv/base.nix
            ./nix/modules/devenv/cc.nix
          ];
          javascript.imports = [
            ./nix/modules/devenv/base.nix
            ./nix/modules/devenv/javascript.nix
          ];
          ocaml.imports = [
            ./nix/modules/devenv/base.nix
            ./nix/modules/devenv/ocaml.nix
          ];
          python.imports = [
            ./nix/modules/devenv/base.nix
            ./nix/modules/devenv/python.nix
          ];
        };
      };
      systems = [
        "x86_64-linux"
        "x86_64-darwin"
        "aarch64-linux"
        "aarch64-darwin"
      ];
    };
}
