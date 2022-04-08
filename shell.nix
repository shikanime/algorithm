{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {
  buildInputs = [
    pkgs.deno
    pkgs.cmake
    pkgs.clang
    pkgs.elixir
    (pkgs.python3Full.withPackages (ps: with ps; [ poetry ]))
  ];
}
