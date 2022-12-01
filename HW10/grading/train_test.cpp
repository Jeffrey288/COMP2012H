#include <algorithm>
#include <numeric>
#include "dataset.h"
#include "nn.h"
#include <iostream>
using namespace std;

void training(NN&, dataset&, const size_t&);
void testing(NN&, dataset&);

void nn_training_testing(dataset& data){		
	NN nn {
		new LayerLinear(PIXELS, 32),
		new LayerSigmoid,
		new LayerLinear(32   , 16),
		new LayerSigmoid,
		new LayerLinear(16   , 10),
		new LayerSigmoid,
	};

	for (size_t epoch = 0; epoch < 10; epoch++)
	{	
		training(nn, data, epoch);
		testing(nn, data);
	}	
}


void training(NN& nn, dataset& data, const size_t& epoch){
	vector<size_t> Sequence(data.get_data_size(TRAIN_LABEL));
	iota(Sequence.begin(), Sequence.end(), 0);
	random_shuffle(Sequence.begin(), Sequence.end());

	printf("================ Epoch %lu ================\n", epoch+1);

	for (size_t i = 0; i < Sequence.size(); i++) {
		vector<float> input = data.get_a_normalized_image(TRAIN_IMAGE, Sequence[i]);
		vector<float> one_hot_label(10);
		one_hot_label[data.get_a_label(TRAIN_LABEL, Sequence[i])] = 1;
		
		nn.backprop(input, one_hot_label);

		if ((i + 1) % 10 == 0)
			nn.apply();

		if ((i + 1) % 500 == 0) {
			printf("Epoch %lu: %lu / %lu\r", epoch+1, i+1, Sequence.size());
			fflush(stdout);
		}
	}
}


void testing(NN& nn, dataset& data){
	// START OF YOUR IMPLEMENTATION
	int data_size = data.get_data_size(TEST_LABEL);
	int label_frequencies[10] = {0};
	int frequency[10] = {0};
	for (int i = 0; i < data_size; i++) {
		vector<float> image = data.get_a_normalized_image(TEST_IMAGE, i);
		vector<float> probs = nn(image);
		int max_prob = 0;
		// cout << probs[0] << " ";
		for (int i = 1; i <= 9; i++) {
			if (probs[i] > probs[max_prob]) max_prob = i;
			// cout << probs[i] << " ";
		}
		// cout << max_prob << " " << data.get_a_label(TEST_LABEL, i) << endl;
		
		if (data.get_a_label(TEST_LABEL, i) == max_prob) {
			frequency[max_prob]++;
		}
		label_frequencies[data.get_a_label(TEST_LABEL, i)]++;
	}
	int sum = 0;
	for (int i = 0; i <= 9; i++) sum += frequency[i];
	printf("Overall accuracy: %.2f%\n", (float) sum / data_size * 100);
	for (int i = 0; i <= 9; i++) {
		printf("Accuracy for digit %d: %.2f%\n", i, (float) frequency[i] / label_frequencies[i] * 100);
	}
	// END OF YOUR IMPLEMENTATION
}
