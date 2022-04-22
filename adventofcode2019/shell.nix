{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {
  buildInputs = [
    pkgs.nodejs
    pkgs.opam
    pkgs.yarn
  ];
}
