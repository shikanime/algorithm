{
  perSystem =
    { pkgs, ... }:
    {
      treefmt = {
        programs = {
          clang-format.enable = true;
          cmake-format.enable = true;
        };
        settings.global.excludes = [
          "algorithm-cc/share/*"
        ];
      };
      checks.cc =
        pkgs.runCommandLocal "cc"
          { src = ../../algorithm-cc; }
          ''
            ${pkgs.cmake}/bin/cmake \
              --preset unknown-unknown-gnu \
              -B out/build/unknown-unknown-gnu
            ${pkgs.cmake}/bin/cmake \
              --build out/build/unknown-unknown-gnu
            ${pkgs.cmake}/bin/ctest \
              --preset unknown-unknown-gnu \
              --test-dir out/build/unknown-unknown-gnu
          '';
      devenv.shells.cc.imports = [
        ../devenv/base.nix
        ../devenv/cc.nix
      ];
    };
}