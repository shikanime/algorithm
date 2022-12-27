{ pkgs, ... }:

{
  packages = [
    pkgs.opam
    pkgs.ocaml
    pkgs.ocaml-ng.ocamlPackages.dune_3
    pkgs.ocaml-ng.ocamlPackages.ocaml-lsp
  ];
}
