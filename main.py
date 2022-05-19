import ctypes
lib = ctypes.CDLL('./lib.so')
lib.create_timetable.argtypes = [ctypes.c_char_p]
lib.create_timetable.restype = ctypes.c_void_p
lib.print_timetable.argtypes = [ctypes.c_void_p]
a = ctypes.create_string_buffer(str.encode('./airports.txt'))
t = lib.create_timetable(a)
lib.print_timetable(t)
