FROM kapil/theano:latest-gpu
WORKDIR /code
ADD . /code
RUN pip install -r requirements.txt

RUN \
	rm -rf data && \
	mkdir data && \
	cd data && \
	wget http://www.iro.umontreal.ca/~lisa/deep/data/mnist/mnist.pkl.gz && \
	cd ..

CMD ["/usr/bin/env","THEANO_FLAGS=mode=FAST_RUN,device=gpu,floatX=float32 python", "/code/nn.py"]
