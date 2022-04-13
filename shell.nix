{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {
  buildInputs = [
    pkgs.deno
    pkgs.cmake
    pkgs.clang
    pkgs.clang-tools
    pkgs.elixir
    pkgs.openssl
    (pkgs.python39.withPackages (ps: with ps; [ poetry ]))
  ];
}
