from ctypes import windll, c_int

def run(dll_path):
    print(f"windll.LoadLibrary {dll_path}")
    dll = windll.LoadLibrary(dll_path)
    print(f"Call Add in {dll}")
    s = dll.Add(c_int(20), c_int(30))
    print(f"result {s}")


if __name__ == '__main__':
    import os
    base_dir = os.path.dirname(os.path.dirname(__file__))
    run(os.path.join(base_dir, 'c/c_add.dll'))
    run(os.path.join(base_dir, 'cpp/cpp_add.dll'))
    run(os.path.join(base_dir, 'go/go_add.dll'))

