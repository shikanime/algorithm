{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {
  nativeBuildInputs = [
    pkgs.cmake
    pkgs.gcc11
  ];
  buildInputs = [
    pkgs.clang-tools
    pkgs.openssl
  ];
}
