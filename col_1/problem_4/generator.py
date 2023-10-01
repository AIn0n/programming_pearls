import argparse
from random import shuffle

DEF_OUT_DIR = "output.txt"


def main(n: int, output: str) -> None:
    if output is None:
        output = DEF_OUT_DIR

    numbers = list(range(0, n))
    shuffle(numbers)
    with open(output, "wt") as f:
        for number in numbers:
            print(number, file=f)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="generate N numbers in random order and write this to the file as strings."
    )
    parser.add_argument(
        "-n", "--number", type=int, help="max number exclusive", required=True
    )
    parser.add_argument(
        "-o", "--output", type=str, help=f"path to output file. Default: {DEF_OUT_DIR}"
    )
    args = parser.parse_args()
    main(args.number, args.output)
