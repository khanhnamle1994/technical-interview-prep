class WordCloudData(object):

    def __init__(self, input_string):
        self.words_to_counts = {}
        self.populate_words_to_counts(input_string)

    def populate_words_to_counts(self, input_string):
        current_word_start_index = 0
        current_word_length = 0

        for i, character in enumerate(input_string):
            if i == len(input_string) - 1:
                if character.isalpha():
                    current_word_length += 1
                if current_word_length > 0:
                    current_word = input_string[current_word_start_index:current_word_start_index + current_word_length]
                    self.add_word_to_dictionary(current_word)

            elif character == ' ' or character == '\u2014':
                if current_word_length > 0:
                    current_word = input_string[current_word_start_index:current_word_start_index + current_word_length]
                    self.add_word_to_dictionary(current_word)
                    current_word_length = 0

            elif character == '.':
                if i < len(input_string) - 1 and input_string[i+1] == '.':
                    if current_word_length > 0:
                        current_word = input_string[current_word_start_index:current_word_start_index + current_word_length]
                        self.add_word_to_dictionary(current_word)
                        current_word_length = 0

            elif character.isalpha() or character == '\'':
                if current_word_length == 0:
                    current_word_start_index = i
                current_word_length += 1

            elif character == '-':
                if i > 0 and input_string[i-1].isalpha() and input_string[i+1].isalpha():
                    if current_word_length == 0:
                        current_word_start_index = i
                    current_word_length += 1

                elif:
                    if current_word_length > 0:
                        current_word = input_string[current_word_start_index:current_word_start_index + current_word_length]
                        self.add_word_to_dictionary(current_word)
                        current_word_length = 0

    def add_word_to_dictionary(self, word):
        if word in self.words_to_counts:
            self.words_to_counts[word] += 1

        elif word.lower() in self.words_to_counts:
            self.words_to_counts[word.lower()] += 1

        elif word.capitalize() in self.words_to_counts:
            self.words_to_counts[word] = 1
            self.words_to_counts[word] += self.words_to_counts[word.capitalize()]
            del self.words_to_counts[word.capitalize()]

        else:
            self.words_to_counts[word] = 1
