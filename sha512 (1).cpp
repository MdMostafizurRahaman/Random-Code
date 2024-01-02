#include <bits/stdc++.h>
using namespace std;
#define input_file "input.txt"
#define block_size 1024
#define number_of_steps 80
#define Ch(e, f, g) ((e & f) ^ (~e & g))
#define Maj(a, b, c) ((a & b) ^ (a & c) ^ (b & c))
#define RotR(x, n) ((x >> n) | (x << (64 - n)))
#define Sum0(x) ((RotR(x, 28)) ^ (RotR(x, 34)) ^ (RotR(x, 39)))
#define Sum1(x) ((RotR(x, 14)) ^ (RotR(x, 18)) ^ (RotR(x, 41)))
#define Sigma0(x) (RotR(x, 1) ^ RotR(x, 8) ^ (x >> 7))
#define Sigma1(x) (RotR(x, 19) ^ RotR(x, 61) ^ (x >> 6))
typedef unsigned long long uint64t;

uint64t W[80];
uint64t initial_vector[8] = {0x6a09e667f3bcc908ULL,
                             0xbb67ae8584caa73bULL,
                             0x3c6ef372fe94f82bULL,
                             0xa54ff53a5f1d36f1ULL,
                             0x510e527fade682d1ULL,
                             0x9b05688c2b3e6c1fULL,
                             0x1f83d9abfb41bd6bULL,
                             0x5be0cd19137e2179ULL};
uint64t IV[8] = {0x6a09e667f3bcc908ULL,
                 0xbb67ae8584caa73bULL,
                 0x3c6ef372fe94f82bULL,
                 0xa54ff53a5f1d36f1ULL,
                 0x510e527fade682d1ULL,
                 0x9b05688c2b3e6c1fULL,
                 0x1f83d9abfb41bd6bULL,
                 0x5be0cd19137e2179ULL};
const uint64t k[80] = {0x428a2f98d728ae22ULL, 0x7137449123ef65cdULL, 0xb5c0fbcfec4d3b2fULL, 0xe9b5dba58189dbbcULL, 0x3956c25bf348b538ULL,
                       0x59f111f1b605d019ULL, 0x923f82a4af194f9bULL, 0xab1c5ed5da6d8118ULL, 0xd807aa98a3030242ULL, 0x12835b0145706fbeULL,
                       0x243185be4ee4b28cULL, 0x550c7dc3d5ffb4e2ULL, 0x72be5d74f27b896fULL, 0x80deb1fe3b1696b1ULL, 0x9bdc06a725c71235ULL,
                       0xc19bf174cf692694ULL, 0xe49b69c19ef14ad2ULL, 0xefbe4786384f25e3ULL, 0x0fc19dc68b8cd5b5ULL, 0x240ca1cc77ac9c65ULL,
                       0x2de92c6f592b0275ULL, 0x4a7484aa6ea6e483ULL, 0x5cb0a9dcbd41fbd4ULL, 0x76f988da831153b5ULL, 0x983e5152ee66dfabULL,
                       0xa831c66d2db43210ULL, 0xb00327c898fb213fULL, 0xbf597fc7beef0ee4ULL, 0xc6e00bf33da88fc2ULL, 0xd5a79147930aa725ULL,
                       0x06ca6351e003826fULL, 0x142929670a0e6e70ULL, 0x27b70a8546d22ffcULL, 0x2e1b21385c26c926ULL, 0x4d2c6dfc5ac42aedULL,
                       0x53380d139d95b3dfULL, 0x650a73548baf63deULL, 0x766a0abb3c77b2a8ULL, 0x81c2c92e47edaee6ULL, 0x92722c851482353bULL,
                       0xa2bfe8a14cf10364ULL, 0xa81a664bbc423001ULL, 0xc24b8b70d0f89791ULL, 0xc76c51a30654be30ULL, 0xd192e819d6ef5218ULL,
                       0xd69906245565a910ULL, 0xf40e35855771202aULL, 0x106aa07032bbd1b8ULL, 0x19a4c116b8d2d0c8ULL, 0x1e376c085141ab53ULL,
                       0x2748774cdf8eeb99ULL, 0x34b0bcb5e19b48a8ULL, 0x391c0cb3c5c95a63ULL, 0x4ed8aa4ae3418acbULL, 0x5b9cca4f7763e373ULL,
                       0x682e6ff3d6b2b8a3ULL, 0x748f82ee5defb2fcULL, 0x78a5636f43172f60ULL, 0x84c87814a1f0ab72ULL, 0x8cc702081a6439ecULL,
                       0x90befffa23631e28ULL, 0xa4506cebde82bde9ULL, 0xbef9a3f7b2c67915ULL, 0xc67178f2e372532bULL, 0xca273eceea26619cULL,
                       0xd186b8c721c0c207ULL, 0xeada7dd6cde0eb1eULL, 0xf57d4f7fee6ed178ULL, 0x06f067aa72176fbaULL, 0x0a637dc5a2c898a6ULL,
                       0x113f9804bef90daeULL, 0x1b710b35131c471bULL, 0x28db77f523047d84ULL, 0x32caab7b40c72493ULL, 0x3c9ebe0a15c9bebcULL,
                       0x431d67c49c100d4cULL, 0x4cc5d4becb3e42b6ULL, 0x597f299cfc657e2aULL, 0x5fcb6fab3ad6faecULL, 0x6c44198c4a475817ULL};

void round(int t)
{
  uint64_t T1 = IV[7] + Ch(IV[4], IV[5], IV[6]) + Sum1(IV[4]) + W[t] + k[t];
  uint64_t T2 = Sum0(IV[0]) + Maj(IV[0], IV[1], IV[2]);

  IV[7] = IV[6];
  IV[6] = IV[5];
  IV[5] = IV[4];
  IV[4] = IV[3] + T1;
  IV[3] = IV[2];
  IV[2] = IV[1];
  IV[1] = IV[0];
  IV[0] = T1 + T2;
  // printf("round %d\n",t);
  // for (int i = 0; i < 8; i++) printf("%lX ",IV[i]);
  // printf("\n");
}

void F(uint64t *block, int block_number)
{
  for (int i = 0; i < 16; i++)
    W[i] = block[i];
  for (int i = 16; i < number_of_steps; i++)
    W[i] = W[i - 16] + W[i - 7] + Sigma0(W[i - 15]) + Sigma1(W[i - 2]);
  for (int i = 0; i < number_of_steps; i++)
    round(i);
  for (int i = 0; i < 8; i++)
    initial_vector[i] = IV[i] + initial_vector[i];
  for (int i = 0; i < 8; i++)
    IV[i] = initial_vector[i];
}

void SHA_512(const string s)
{
  // finding the message length in bits, then number of zeros needed for padding
  // and number of total blocks

  const unsigned char *message = (unsigned char *)s.c_str();
  size_t message_length = strlen((const char *)message);
  size_t message_length_in_bits = (message_length)*8;
  size_t number_of_zeros = (896 - 1 - message_length_in_bits) % 1024;
  uint64t number_of_blocks = (message_length_in_bits + 1 + number_of_zeros + 128) / block_size;

  // padding the extra bits after the actual message
  uint64t padded_message[number_of_blocks][(block_size / 64)];
  uint64t temp = 0x0ULL;
  for (int i = 0; i < number_of_blocks; i++) // i=block iterator each block is 16 byte means 128 bit
  {
    for (int j = 0; j < 128; j++)
    {
      uint64t current_index = i * 128 + j;
      if (current_index < message_length)
        temp = (temp << 8) | (uint64t)(message[current_index]);
      else if (current_index == message_length) // padding 1 here hex 80 is 1000 0000 in binary
        temp = (temp << 8) | 0x80ULL;
      else
        temp = (temp << 8) | 0x0ULL;
      if (((current_index + 1) % 8) == 0)
      {
        padded_message[i][((current_index - 7) / 8) % 16] = temp; // if current index is 135 then we are in 2nd block 0th word
        temp = 0x0ULL;
      }
    }
  }
  padded_message[number_of_blocks - 1][14] = 0x0ULL;
  padded_message[number_of_blocks - 1][15] = message_length_in_bits;
  //   for (int i = 0; i < number_of_blocks; i++)
  //   {
  //     for (int j = 0; j < 16; j++) printf("%llX" ,padded_message[i][j]);
  //   }

  for (int i = 0; i < number_of_blocks; i++)
    F(padded_message[i], i);
}

int main(void)
{
  // string message="A.C. Monza is a professional football club that is based in Monza, Lombardy, Italy. The team plays in the Serie A, the first tier of Italian football, following promotion in the 2021–22 Serie B season. The club was founded in 1912 (first lineup pictured), with its first recorded win on 20 September 1912. On multiple occasions in the 1970s, the club came close to promotion to the Serie A, but were twice declared bankrupt, in 2004 and 2015. Following Silvio Berlusconi's 2018 takeover of the club, Monza was promoted to the Serie B in 2020 after a 19-year absence; no Italian team had played more Serie B seasons (40) without playing in the Serie A. Monza have won the Coppa Italia Serie C a record four times, the Serie C championship four times, and an Anglo-Italian Cup. Monza's colours were initially blue and white but were changed to red and white in 1932; as a result, they are nicknamed i biancorossi ('the white and reds'). They have played home matches at the Stadio Brianteo since 1988.";
  // string message="Sifat";

  ifstream input(input_file); // taking file as inputstream
  string message;
  if (input)
  {
    ostringstream ss;
    ss << input.rdbuf(); // reading data
    message = ss.str();
  }

  SHA_512(message);
  cout << endl
       << "Message digest:- " << endl;
  for (int i = 0; i < 8; i++)
    printf("%llX ", initial_vector[i]);
  cout << endl
       << endl;
}
