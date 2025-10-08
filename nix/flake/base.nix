{
  perSystem = _: {
    treefmt = {
      projectRootFile = "flake.nix";
      enableDefaultExcludes = true;
      programs = {
        nixfmt.enable = true;
        statix.enable = true;
        shfmt.enable = true;
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
