{
  perSystem = _: {
    treefmt.programs.ocamlformat.enable = true;
    devenv.shells.ocaml.imports = [
      ../devenv/base.nix
      ../devenv/ocaml.nix
    ];
  };
}
