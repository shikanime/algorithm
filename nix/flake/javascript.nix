{
  perSystem = _: {
    treefmt.programs.prettier.enable = true;
    devenv.shells.javascript.imports = [
      ../devenv/base.nix
      ../devenv/javascript.nix
    ];
  };
}
