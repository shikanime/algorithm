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
    devenv.shells.default.imports = [
      ../devenv/base.nix
    ];
  };
}
