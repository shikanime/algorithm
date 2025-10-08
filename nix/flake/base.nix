{
  perSystem = _: {
    treefmt = {
      projectRootFile = "flake.nix";
      enableDefaultExcludes = true;
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
