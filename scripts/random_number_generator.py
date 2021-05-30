import sys
import random
import secrets



def gen_hex(length: int):
    return secrets.token_hex(length).upper


def gen_float(start: float, end: float, precision: int=2):
    round(random.uniform(1,2), precision)


def gen_float_w(arr: list):
    gen_float(arr[0], arr[1], arr[2])


def main(argv = sys.argv[1:]):
    if len(argv) < 1:
        pass
    elif tmp := argv[0]:
        if 0:
            pass
        elif tmp == "h":
            if len(argv[1:]) < 1:
                pass
            else:
                gen_hex(argv[1])
        elif tmp == "f":
            if len(argv[1:]) < 3:
                pass
            else:
                gen_float(argv[1:])


if __name__ == "__main__":
    main()
