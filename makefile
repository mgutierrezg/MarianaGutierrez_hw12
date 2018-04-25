grafica.pdf : advection.txt MG_graph.py
	python MG_graph.py
advection.txt: advec
	./advec > advection.txt
advec: MG_advection.cpp
	c++ MG_advection.cpp -o advec
