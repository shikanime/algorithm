{ pkgs ? import <nixpkgs> { } }:

let
  vscode = {
    cmakeKits = pkgs.writeText "cmake-kits.json" (builtins.toJSON [
      {
        name = "Nix";
        environmentVariables = {
          CMAKE_INCLUDE_PATH = builtins.concatStringsSep ":"
            [
              "${pkgs.libcxx.dev}/include"
              "${pkgs.libcxxabi.dev}/include"
              "${pkgs.openssl.dev}/include"
            ];
          CMAKE_LIBRARY_PATH = builtins.concatStringsSep ":"
            [
              "${pkgs.libcxx}/lib"
              "${pkgs.libcxxabi}/lib"
              "${pkgs.openssl}/lib"
            ];
        };
        compilers = {
          C = "${pkgs.gcc11}/bin/gcc";
          CXX = "${pkgs.gcc11}/bin/g++";
        };
      }
    ]);
    settings = pkgs.writeText "settings.json" (builtins.toJSON {
      "cmake.cmakePath" = "${pkgs.cmake}/bin/cmake";
      "cmake.ctestPath" = "${pkgs.cmake}/bin/ctest";
    });
  };
in
pkgs.mkShell
{
  nativeBuildInputs = [
    pkgs.cmake
    pkgs.gcc11
  ];
  buildInputs = [
    pkgs.clang-tools
    pkgs.openssl
  ];
  shellHook = ''
    cp -rf ${vscode.cmakeKits} .vscode/cmake-kits.json
    cp -rf ${vscode.settings} .vscode/settings.json
  '';

}
