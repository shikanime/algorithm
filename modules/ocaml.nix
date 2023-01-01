{ pkgs, ... }:

{
  packages = [
    pkgs.opam
    pkgs.ocaml
    pkgs.ocamlPackages.dune_3
    pkgs.ocamlPackages.ocaml-lsp
  ];
}
