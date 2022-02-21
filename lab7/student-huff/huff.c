// code for a huffman coder


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "huff.h"
#include "bitfile.h"


// create a new huffcoder structure
struct huffcoder *  huffcoder_new()
{
  struct huffcoder * huff = malloc(sizeof(struct huffcoder)); //allocate memory
  huff->tree = NULL; //tree is null
  return huff; //return
}

// count the frequency of characters in a file; set chars with zero
// frequency to one
void huffcoder_count(struct huffcoder * this, char * filename)
{
  FILE * fp = fopen(filename, "r"); //open file
  assert(fp != NULL); //check if file is null
  char current_char = 0; //initialise character variable
  while(!feof(fp)){
    current_char = fgetc(fp); //get next char if not end of file
    if (!feof(fp)){
      this->freqs[(int)current_char]++; //increment frequency
    }
  }
  for (int i = 0; i < NUM_CHARS; i++){
    if (this->freqs[i] == 0) this->freqs[i] = 1; //initialise all zero frequencies to 1
  }
  fclose(fp); //close file pointer
}



// using the character frequencies build the tree of compound
// and simple characters that are used to compute the Huffman codes

struct huffchar * make_compound(struct huffchar * node1, struct huffchar * node2, int current_seqno){
  struct huffchar * comp = malloc(sizeof(struct huffchar)); //allocate memory
  comp->u.compound.left = node1; //update left char to be smallest freq
  comp->u.compound.right = node2; //update right char to be largest freq
  comp->is_compound = 1; //update compound to true
  comp->seqno = current_seqno; //update sequence number
  comp->freq = (node1->freq + node2->freq); //update combined frequencies
  return comp; //return
}

int get_size(struct huffchar * roots[NUM_CHARS])
{
	int number_of_nodes = 0;
	for(int i = 0; i<NUM_CHARS; i++)
	{
		if(roots[i] != NULL)	number_of_nodes++;
	}
	return number_of_nodes;
}

int lowest_index(struct huffchar * roots[NUM_CHARS]){
  int size = get_size(roots);
  int lowest_index = 0;
  for(int i = 0; i < size; i ++)
  {
    if(roots[i]->freq < roots[lowest_index]->freq)
    lowest_index = i;
    else if((roots[i]->freq == roots[lowest_index]->freq) && (roots[i]->u.c > roots[lowest_index]->u.c))
    lowest_index = i;
  }
  return lowest_index;
}

void huffcoder_build_tree(struct huffcoder * this)
{
  struct huffchar * roots[NUM_CHARS];
  for(int i = 0; i<NUM_CHARS; i++){
    struct huffchar * p = malloc(sizeof(struct huffchar)); //allocate memory
    p->u.compound.left = 0;
    p->u.compound.right = 0;
    p->is_compound = 0;			//set freq to char freq
    p->seqno = ((char) i); //update sequence number to i
    p->freq = this->freqs[i]; //update frequency to i frequency
    p->u.c = ((char) i); //update char to i
    roots[i] = p;
  }
  int size = get_size(roots);
  int current_seq = NUM_CHARS;
  int lowest_left = 0;
  int lowest_right = 0;
  int lowest_root = 0;
  while (size > 1){
    lowest_left = lowest_index(roots);
    lowest_right = lowest_index(roots);
    struct huffchar * lowest_node_1 = roots[lowest_left];
    struct huffchar * lowest_node_2 = roots[lowest_right];
    roots[lowest_left] = NULL;
    roots[lowest_right] = NULL;
    struct huffchar * compound_node = make_compound(lowest_node_1, lowest_node_2, current_seq);
		current_seq++;
    lowest_root = lowest_left;
		roots[lowest_root] = compound_node;
  }
  lowest_root = lowest_index(roots);
  this->tree = roots[lowest_root];
}




// using the Huffman tree, build a table of the Huffman codes
// with the huffcoder object

void tree2table_recursive(struct huffcoder * this, struct huffchar * node,
		 int path, int depth)
{
  if(node->is_compound)
	{
    path = path << 1;
    tree2table_recursive(this,node->u.compound.left, path, depth+1);
    path = path | 1;
    tree2table_recursive(this, node->u.compound.right, path, depth+1);
  }
  if(!node->is_compound)
	{
    unsigned char index = node->u.c;
		this->codes[(unsigned int)index]=path;
		this->code_lengths[(unsigned int)index]=depth;
  }
}
void huffcoder_tree2table(struct huffcoder * this)
{
  int path=0;
  int depth=0;
  fprintf(stderr, "Test: \n");
  tree2table_recursive(this, this->tree, path, depth);
}


// print the Huffman codes for each character in order
void huffcoder_print_codes(struct huffcoder * this)
{
  int i, j;
  char buffer[NUM_CHARS];

  for ( i = 0; i < NUM_CHARS; i++ ) {
    // put the code into a string
    assert(this->code_lengths[i] < NUM_CHARS);
    for ( j = this->code_lengths[i]-1; j >= 0; j--) {
      buffer[j] = ((this->codes[i] >> j) & 1) + '0';
    }
    // don't forget to add a zero to end of string
    buffer[this->code_lengths[i]] = '\0';

    // print the code
    printf("char: %d, freq: %d, code: %s\n", i, this->freqs[i], buffer);;
  }
}



// encode the input file and write the encoding to the output file
void huffcoder_encode(struct huffcoder * this, char * input_filename,
  char * output_filename)
  {

  }

  // decode the input file and write the decoding to the output file
  void huffcoder_decode(struct huffcoder * this, char * input_filename,
    char * output_filename)
    {

    }
