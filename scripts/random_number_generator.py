import sys
import random
import secrets


ret = ""

def gen_hex(length: int):
	return secrets.token_hex(length).upper()


def gen_float(start: float, end: float, precision: float=2):
    return round(random.uniform(start, end), int(precision))


def gen_float_w(arr_o: list):
	arr = [float(q) for q in arr_o]
	return gen_float(arr[0], arr[1], arr[2])


def main(argv = sys.argv[1:]):
	if len(argv) < 1:
		pass
	else:
		tmp = argv[0]
		if 0:
			pass
		elif tmp == "h":
			if len(argv[1:]) < 1:
				pass
			else:
				ret = gen_hex(int(argv[1]))
				print(ret)
		elif tmp == "f":
			if len(argv[1:]) < 3:
				pass
			else:
				ret = gen_float_w(argv[1:])
				print(ret)

if __name__ == "__main__":
	main()
