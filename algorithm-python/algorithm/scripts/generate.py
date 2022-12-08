from pathlib import Path
from jinja2_strcase.jinja2_strcase import to_snake
import jinja2
import argparse


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("name", type=str, nargs="?")
    parser.add_argument("--path", type=str, required=True)
    parser.add_argument("--template", type=str, required=True)
    args, _ = parser.parse_known_args()

    loader = jinja2.PackageLoader("algorithm", f"templates/{args.template}")
    env = jinja2.Environment(
        loader=loader, extensions=["jinja2_strcase.StrcaseExtension"]
    )

    path = Path(args.path)
    path.mkdir(parents=True, exist_ok=True)

    test_file = path / f"{to_snake(args.name)}_test.py"
    with test_file.open("w", encoding="utf-8") as f:
        test_template = env.get_template("test.py.jinja2")
        f.write(test_template.render(name=args.name))

    source_file = path / f"{to_snake(args.name)}.py"
    with source_file.open("w", encoding="utf-8") as f:
        source_template = env.get_template("source.py.jinja2")
        f.write(source_template.render(name=args.name))


if __name__ == "__main__":
    main()
