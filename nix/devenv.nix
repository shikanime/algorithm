{
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
        ./modules/base.nix
      ];
      beam.imports = [
        ./modules/base.nix
        ./modules/beam.nix
      ];
      cc.imports = [
        ./modules/base.nix
        ./modules/cc.nix
      ];
      javascript.imports = [
        ./modules/base.nix
        ./modules/javascript.nix
      ];
      ocaml.imports = [
        ./modules/base.nix
        ./modules/ocaml.nix
      ];
      python.imports = [
        ./modules/base.nix
        ./modules/python.nix
      ];
    };
  };
}
