#include <chrono>
#include <iostream>
#include <array>

using namespace std;

// Here you should implement your
// magic checker. It should return
// true if the square is magic,
// false otherwise.
//
//                8 1 6    this is
// "816357492" =  3 5 7    a magic
//                4 9 2    square
//
#ifdef ONE
__attribute__((noinline))
bool check_if_magic(const std::string& square)
{
    // math fact (probably not honest :) )
    if (square[4] != '5')
        return false;

    const int sum = '0' * 3 + 15;

    if (
            square[2] + square[4] + square[6] != sum ||

            square[0] + square[1] + square[2] != sum || // rows
            // square[3] + square[4] + square[5] != sum ||
            square[6] + square[7] + square[8] != sum ||

            square[0] + square[3] + square[6] != sum || // cols
            // square[1] + square[4] + square[7] != sum ||
            square[2] + square[5] + square[8] != sum ||

            square[0] + square[4] + square[8] != sum ||

            false // used for swapping lines easier
       )
        return false;

    char x = ( ( square[0] ^ square[1] ) ^ ( square[2] ^ square[3] ) ) ^ ( ( square[5] ^ square[6] ) ^ ( square[7] ^ square[8] ) ) ;
    if (x != (49 ^ (int)'5'))
        return false;

    char o = ( ( square[0] | square[1] ) | ( square[2] | square[3] ) ) | ( ( square[5] | square[6] ) | ( square[7] | square[8] ) ) ;
    if ( o != 63 )
        return false;

    return true;
}

#elif TWO

__attribute__((noinline))
bool check_if_magic(const std::string& sq)
{
  if(sq[4] != '5')
    return false;

  uint64_t magic_number =
    *(reinterpret_cast<const uint32_t*>
      (sq.data()));
  magic_number <<= 32;
  magic_number +=
    *(reinterpret_cast<const uint32_t*>
      (sq.data()+5));

  if(
  magic_number == 3545515123101087289 ||
  magic_number == 3690191062107239479 ||
  magic_number == 3544956562637535289 ||
  magic_number == 3978984379655991859 ||
  magic_number == 3689073941180135479 ||
  magic_number == 4123101758198592049 ||
  magic_number == 3977867258728887859 ||
  magic_number == 4122543197735040049
  )
      return true;
  return false;
}

#endif


// this generates all possible combinations
// of 1-9 digits that may or may not
// form a magic square
static string buffer = "000000000";
void generate_or_check(int index_or_check = 8)
{
    if (index_or_check == -1)
    {
        if (check_if_magic(buffer))
            cout << buffer << " ";
        return;
    }

    for (auto i = 1u; i < 10; ++i)
    {
        buffer[index_or_check] = '0' + i;
        generate_or_check(index_or_check - 1);
    }
}

// this runs the generator and measures time
int main()
{
    // check_if_magic("123456789");
    // return 0;
    auto start = std::chrono::system_clock::now();
    generate_or_check();
    auto end = std::chrono::system_clock::now();
    chrono::duration<double> difference = end - start;
    cout << difference.count() << "\n\n";
}
