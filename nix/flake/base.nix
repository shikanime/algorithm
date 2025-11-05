{ inputs, ... }:

{
  perSystem =
    { pkgs, ... }:
    {
      treefmt = {
        enableDefaultExcludes = true;
        projectRootFile = "flake.nix";
        programs = {
          nixfmt.enable = true;
          prettier.enable = true;
          shfmt.enable = true;
          statix.enable = true;
        };
        settings.global.excludes = [
          "LICENSE"
        ];
      };
      devenv = {
        modules = [
          inputs.devlib.devenvModule
        ];
        shells = {
          default.imports = [
            ../devenv/base.nix
          ];
          update = {
            containers = pkgs.lib.mkForce { };
            packages = [
              pkgs.nushell
              pkgs.sapling
            ];
          };
        };
      };
    };
}
