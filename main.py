import ctypes
lib = ctypes.CDLL('./lib.so')
lib.create_timetable.argtypes = [ctypes.c_char_p]
lib.create_timetable.restype = ctypes.c_void_p
lib.print_timetable.argtypes = [ctypes.c_void_p]
filename = input ("Введите название файла: ")
a = ctypes.create_string_buffer(str.encode(filename))
t = lib.create_timetable(a)
lib.print_timetable(t)
