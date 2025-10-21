{ inputs, ... }:

{
  perSystem = _: {
    treefmt = {
      enableDefaultExcludes = true;
      projectRootFile = "flake.nix";
      programs = {
        nixfmt.enable = true;
        prettier.enable = true;
        shfmt.enable = true;
        statix.enable = true;
      };
      settings.global.excludes = [
        "LICENSE"
      ];
    };
    devenv = {
      modules = [
        inputs.devlib.devenvModule
      ];
      shells.default.imports = [
        ../devenv/base.nix
        ../devenv/beam.nix
        ../devenv/cc.nix
        ../devenv/javascript.nix
        ../devenv/ocaml.nix
        ../devenv/python.nix
      ];
    };
  };
}
