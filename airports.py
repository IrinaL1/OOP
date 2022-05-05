import ctypes

lib_airports = ctypes.CDLL('./libmain.so')

lib_airports.test_flight_tp()
lib_airports.main_py()
