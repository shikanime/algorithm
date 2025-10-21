{
  perSystem = _: {
    treefmt = {
      programs = {
        ruff-format.enable = true;
        taplo.enable = true;
      };
      settings.global.excludes = [
        "*.jinja2"
        "*.python-version"
      ];
    };
    devenv.shells.python.imports = [
      ../devenv/base.nix
      ../devenv/python.nix
    ];
  };
}
