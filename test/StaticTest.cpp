#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <cstring>

#include <gtest/gtest.h>

extern "C" {
  #include <nanocdr/nanoCdr.h>
}

  #define BUFFER_LENGTH 2000

  const signed char octet_t = 32;
  const char char_t =  'Z';

  const uint16_t ushort_t = 65500;
  const int16_t short_t = -32700;
  const uint32_t ulong_t = 4294967200;
  const int32_t long_t = -2147483600;

  const uint64_t ulonglong_t = 18446744073709551600u;
  const int64_t longlong_t = -9223372036800;

  const unsigned long long ulonglonglong_t = (uint64_t)18446744073709551600u;
  const long long longlonglong_t = (int64_t)-9223372036800;

  const float float_tt = FLT_MIN;
  const double double_tt = DBL_MIN;
  const long double longdouble_t = DBL_MIN;

  //TODO bool
  //static const bool bool_t = true;

  const char * string_t = "Hola a todos, esto es un test";
  const char * emptystring_t = "";

  const unsigned char octet_array_t[5] = {1, 2, 3, 4, 5};
  const char char_array_t[5] = {'A', 'B', 'C', 'D', 'E'};

  const uint16_t ushort_array_t [5] = {65500, 65501, 65502, 65503, 65504};
  const int16_t short_array_t[5] = {-32700, -32701, -32702, -32703, -32704};

  const uint32_t ulong_array_t[5] = {4294967200, 4294967201, 4294967202, 4294967203, 4294967204};
  const int32_t long_array_t[5] = {-2147483600, -2147483601, -2147483602, -2147483603, -2147483604};


  const uint64_t ulonglong_array_t[5] = {(uint64_t)18446744073709551600u, (uint64_t)18446744073709551601u, (uint64_t)18446744073709551602u, (uint64_t)18446744073709551603u, (uint64_t)18446744073709551604u};
  const int64_t  longlong_array_t[5] = {(int64_t)-9223372036800, (int64_t)-9223372036801, (int64_t)-9223372036802, (int64_t)-9223372036803, (int64_t)-9223372036804};

  const unsigned long long ulonglonglong_array_t[5] = {18446744073709551600u, 18446744073709551601u, 18446744073709551602u, 18446744073709551603u, 18446744073709551604u};
  const long long longlonglong_array_t[5] = {-9223372036800, -9223372036801, -9223372036802, -9223372036803, -9223372036804};

  const float float_array_t[5] = {float_tt, float_tt + 1, float_tt + 2, float_tt + 3, float_tt + 4};
  const double double_array_t[5] = {double_tt, double_tt + 1, double_tt + 2, double_tt + 3, double_tt + 4};
  const long double longdouble_array_t[5] = {longdouble_t, longdouble_t + 1, longdouble_t + 2, longdouble_t + 3, longdouble_t + 4};

  //TODO bool
  //static const std::array<bool, 5> bool_array_t = {{true, false, true, false, true}};
  //static const bool bool_array_2_t[5] = {false, true, false, true, false};

  // Added because error 336.
  const unsigned char octet_seq_t[5] = {5, 4, 3, 2, 1};
  const char char_seq_t[5] = {'E', 'D', 'C', 'B', 'A'};
  const uint16_t ushort_seq_t[5] = {65504, 65503, 65502, 65501, 65500};
  const int16_t short_seq_t[5] = {-32704, -32703, -32702, -32701, -32700};
  const uint32_t ulong_seq_t[5] = {4294967204, 4294967203, 4294967202, 4294967201, 4294967200};
  const int32_t long_seq_t[5] = {-2147483604, -2147483603, -2147483602, -2147483601, -2147483600};

  const uint64_t ulonglong_seq_t[5] = {(uint64_t)18446744073709551604u, (uint64_t)18446744073709551603u, (uint64_t)18446744073709551602u, (uint64_t)18446744073709551601u, (uint64_t)18446744073709551600u};
  const int64_t longlong_seq_t[5] = {(int64_t)-9223372036804, (int64_t)-9223372036803, (int64_t)-9223372036802, (int64_t)-9223372036801, (int64_t)-9223372036800};

  const unsigned long long ulonglonglong_seq_t[5] = {18446744073709551600u, 18446744073709551601u, 18446744073709551602u, 18446744073709551603u, 18446744073709551604u};
  const long long longlonglong_seq_t[5] = {-9223372036800, -9223372036801, -9223372036802, -9223372036803, -9223372036804};


  const float float_seq_t[5] = {float_tt + 4, float_tt + 3, float_tt + 2, float_tt + 1, float_tt};
  const double double_seq_t[5] = {double_tt + 4, double_tt + 3, double_tt + 2, double_tt + 1, double_tt};
  const long double longdouble_seq_t[5] = {longdouble_t, longdouble_t + 1, longdouble_t + 2, longdouble_t + 3, longdouble_t + 4};

  //static const bool bool_seq_t[5] = {true, true, false, false, true};

  const char * string_seq_t[5] = {"HELLO", "BYE", "GOODBYE", "HOLA", "ADIOS"};
  // Added because error 337
  const char * c_string_t = "HOLA";

  Endianness endianness = LITTLE_ENDIANNESS;

  TEST(nanoCDRBasicTests, Char)
  {
      char char_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeChar(char_t, nanoCDRWrite);

      // Deseriazliation.
      deserializeChar(&char_out, nanoCDRRead);

      EXPECT_EQ(char_out, char_t);
  }

  TEST(nanoCDRBasicTests, SignedChar)
  {
      signed char octect_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeSignedChar(octet_t, nanoCDRWrite);

      // Deseriazliation.
      deserializeSignedChar(&octect_out, nanoCDRRead);

      EXPECT_EQ(octect_out, octet_t);
  }

  TEST(nanoCDRBasicTests, Short)
  {
      int16_t short_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeShort(short_t, nanoCDRWrite);

      // Deseriazliation.
      deserializeShort(&short_out, nanoCDRRead);

      EXPECT_EQ(short_out, short_t);
  }

  TEST(nanoCDRBasicTests, UnsignedShort)
  {
      uint16_t ushort_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedShort(ushort_t, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedShort(&ushort_out, nanoCDRRead);

      EXPECT_EQ(ushort_out, ushort_t);
  }

  TEST(nanoCDRBasicTests, Int)
  {
      int32_t long_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeInt(long_t, nanoCDRWrite);

      // Deseriazliation.
      deserializeInt(&long_out, nanoCDRRead);

      EXPECT_EQ(long_out, long_t);
  }

  TEST(nanoCDRBasicTests, UnsignedInt)
  {
      uint32_t ulong_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedInt(ulong_t, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedInt(&ulong_out, nanoCDRRead);

      EXPECT_EQ(ulong_out, ulong_t);
  }

  TEST(nanoCDRBasicTests, Long)
  {
      int64_t long_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLong(longlong_t, nanoCDRWrite);

      // Deseriazliation.
      deserializeLong(&long_out, nanoCDRRead);

      EXPECT_EQ(long_out, longlong_t);
  }

  TEST(nanoCDRBasicTests, uLong)
  {
      uint64_t ulong_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedLong(ulonglong_t, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedLong(&ulong_out, nanoCDRRead);

      EXPECT_EQ(ulong_out, ulonglong_t);
  }

  TEST(nanoCDRBasicTests, LongLong)
  {
      long long longlong_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongLong(longlonglong_t, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongLong(&longlong_out, nanoCDRRead);

      EXPECT_EQ(longlong_out, longlonglong_t);
  }

  TEST(nanoCDRBasicTests, uLongLong)
  {
      unsigned long long ulonglong_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedLongLong(ulonglonglong_t, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedLongLong(&ulonglong_out, nanoCDRRead);

      EXPECT_EQ(ulonglong_out, ulonglonglong_t);
  }

  TEST(nanoCDRBasicTests, Float)
  {
      float float_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeFloat(float_tt, nanoCDRWrite);

      // Deseriazliation.
      deserializeFloat(&float_out, nanoCDRRead);

      EXPECT_EQ(float_out, float_tt);
  }

  TEST(nanoCDRBasicTests, Double)
  {
      double double_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeDouble(double_tt, nanoCDRWrite);

      // Deseriazliation.
      deserializeDouble(&double_out, nanoCDRRead);

      EXPECT_EQ(double_out, double_tt);
  }

  TEST(nanoCDRBasicTests, LongDouble)
  {
      long double longdouble_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongDouble(longdouble_t, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongDouble(&longdouble_out, nanoCDRRead);

      EXPECT_EQ(longdouble_out, longdouble_t);
  }

  TEST(nanoCDRBasicTests, String)
  {
      char * string_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      const uint32_t length = (uint32_t)std::strlen(string_t);
      uint32_t length_out;

      // Serialization.
      serializeString(string_t, length, nanoCDRWrite);

      // Deseriazliation.
      deserializeString(&string_out, &length_out, nanoCDRRead);

      uint32_t comparative = std::strcmp(string_out, string_t);

      EXPECT_EQ(comparative, 0);
      EXPECT_EQ(length, length_out);
      free(string_out);
  }

  TEST(nanoCDRBasicTests, EmptyString)
  {
      char * string_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      const uint32_t length = (uint32_t)std::strlen(emptystring_t);
      uint32_t length_out;

      // Serialization.
      serializeString(emptystring_t, length, nanoCDRWrite);

      // Deseriazliation.
      deserializeString(&string_out, &length_out, nanoCDRRead);

      uint32_t comparative = std::strcmp(string_out, emptystring_t);

      EXPECT_EQ(comparative, 0);
      EXPECT_EQ(length, length_out);
      free(string_out);
  }

  TEST(nanoCDRArrayTests, CharArray)
  {
      char * char_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeCharArray(char_array_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeCharArray(&char_out, 5, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(char_array_t[i], char_out[i]);
      }
      free(char_out);
  }

  TEST(nanoCDRArrayTests, UnsignedCharArray)
  {
      unsigned char * char_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedCharArray(octet_array_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedCharArray(&char_out, 5, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(octet_array_t[i], char_out[i]);
      }
      free(char_out);
  }

  TEST(nanoCDRArrayTests, ShortArray)
  {
      int16_t * short_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeShortArray(short_array_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeShortArray(&short_out, 5, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(short_array_t[i], short_out[i]);
      }
      free(short_out);
  }

  TEST(nanoCDRArrayTests, UnsignedShortArray)
  {
      uint16_t * ushort_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedShortArray(ushort_array_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedShortArray(&ushort_out, 5, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(ushort_array_t[i], ushort_out[i]);
      }
      free(ushort_out);
  }

  TEST(nanoCDRArrayTests, IntArray)
  {
      int32_t * int_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeIntArray(long_array_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeIntArray(&int_out, 5, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(long_array_t[i], int_out[i]);
      }
      free(int_out);
  }

  TEST(nanoCDRArrayTests, UnsignedIntArray)
  {
      uint32_t * uint_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedIntArray(ulong_array_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedIntArray(&uint_out, 5, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(ulong_array_t[i], uint_out[i]);
      }
      free(uint_out);
  }

  TEST(nanoCDRArrayTests, LongArray)
  {
      int64_t * long_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongArray(longlong_array_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongArray(&long_out, 5, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(longlong_array_t[i], long_out[i]);
      }
      free(long_out);
  }

  TEST(nanoCDRArrayTests, ULongArray)
  {
      uint64_t * ulong_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedLongArray(ulonglong_array_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedLongArray(&ulong_out, 5, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(ulonglong_array_t[i], ulong_out[i]);
      }
      free(ulong_out);
  }

  TEST(nanoCDRArrayTests, LongLongArray)
  {
      long long * longlong_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongLongArray(longlonglong_array_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongLongArray(&longlong_out, 5, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(longlonglong_array_t[i], longlong_out[i]);
      }
      free(longlong_out);
  }

  TEST(nanoCDRArrayTests, ULongLongArray)
  {
      unsigned long long * ulonglong_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedLongLongArray(ulonglonglong_array_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedLongLongArray(&ulonglong_out, 5, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(ulonglonglong_array_t[i], ulonglong_out[i]);
      }
      free(ulonglong_out);
  }

  TEST(nanoCDRArrayTests, FloatArray)
  {
      float * float_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeFloatArray(float_array_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeFloatArray(&float_out, 5, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(float_array_t[i], float_out[i]);
      }
      free(float_out);
  }

  TEST(nanoCDRArrayTests, DoubleArray)
  {
      double * double_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeDoubleArray(double_array_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeDoubleArray(&double_out, 5, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(double_array_t[i], double_out[i]);
      }

      free(double_out);
  }

  TEST(nanoCDRArrayTests, LongDoubleArray)
  {
      long double * longdouble_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongDoubleArray(longdouble_array_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongDoubleArray(&longdouble_out, 5, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(longdouble_array_t[i], longdouble_out[i]);
      }
      free(longdouble_out);
  }

  TEST(nanoCDRArrayTests, StringArray)
  {
      char ** string_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeStringArray(string_seq_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeStringArray(&string_out, 5, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        int32_t length_in_aux = (uint32_t)std::strlen(string_seq_t[i]);
        int32_t length_out_aux = (uint32_t)std::strlen(string_out[i]);
        int32_t comparative_aux = std::strcmp(string_seq_t[i], string_out[i]);
        EXPECT_EQ(length_in_aux, length_out_aux);
        EXPECT_EQ(comparative_aux, 0);
        free(string_out[i]);
      }
      free(string_out);
  }

  TEST(nanoCDRSequencesTests, CharSequence)
  {
      char * char_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeCharSequence(char_seq_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeCharSequence(&char_out, &size_out, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(char_seq_t[i], char_out[i]);
      }

      free(char_out);
  }

  TEST(nanoCDRSequencesTests, UnsignedCharSequence)
  {
      unsigned char * char_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedCharSequence(octet_seq_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedCharSequence(&char_out, &size_out, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(octet_seq_t[i], char_out[i]);
      }

      free(char_out);
  }

  TEST(nanoCDRSequencesTests, ShortSequence)
  {
      int16_t * short_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeShortSequence(short_seq_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeShortSequence(&short_out, &size_out, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(short_seq_t[i], short_out[i]);
      }

      free(short_out);
  }

  TEST(nanoCDRSequencesTests, UnsignedShortSequence)
  {
      uint16_t * ushort_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedShortSequence(ushort_seq_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedShortSequence(&ushort_out, &size_out, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(ushort_seq_t[i], ushort_out[i]);
      }

      free(ushort_out);
  }

  TEST(nanoCDRSequencesTests, IntSequence)
  {
      int32_t * int_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeIntSequence(long_seq_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeIntSequence(&int_out, &size_out, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(long_seq_t[i], int_out[i]);
      }

      free(int_out);
  }

  TEST(nanoCDRSequencesTests, UnsignedIntSequence)
  {
      uint32_t * uint_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedIntSequence(ulong_seq_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedIntSequence(&uint_out, &size_out, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(ulong_seq_t[i], uint_out[i]);
      }

      free(uint_out);
  }

  TEST(nanoCDRSequencesTests, LongSequence)
  {
      int64_t * long_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongSequence(longlong_seq_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongSequence(&long_out, &size_out, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(longlong_seq_t[i], long_out[i]);
      }

      free(long_out);
  }

  TEST(nanoCDRSequencesTests, ULongSequence)
  {
      uint64_t * ulong_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedLongSequence(ulonglong_seq_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedLongSequence(&ulong_out, &size_out, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(ulonglong_seq_t[i], ulong_out[i]);
      }

      free(ulong_out);
  }

  TEST(nanoCDRSequencesTests, LongLongSequence)
  {
      long long * longlong_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongLongSequence(longlonglong_seq_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongLongSequence(&longlong_out, &size_out, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(longlonglong_seq_t[i], longlong_out[i]);
      }

      free(longlong_out);
  }

  TEST(nanoCDRSequencesTests, ULongLongSequence)
  {
      unsigned long long * ulonglong_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedLongLongSequence(ulonglonglong_seq_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedLongLongSequence(&ulonglong_out, &size_out, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(ulonglonglong_seq_t[i], ulonglong_out[i]);
      }

      free(ulonglong_out);
  }

  TEST(nanoCDRSequencesTests, FloatSequence)
  {
      float * float_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeFloatSequence(float_seq_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeFloatSequence(&float_out, &size_out, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(float_seq_t[i], float_out[i]);
      }

      free(float_out);
  }

  TEST(nanoCDRSequencesTests, DoubleSequence)
  {
      double * double_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeDoubleSequence(double_seq_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeDoubleSequence(&double_out, &size_out, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(double_seq_t[i], double_out[i]);
      }

      free(double_out);
  }

  TEST(nanoCDRSequencesTests, LongDoubleSequence)
  {
      long double * longdouble_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongDoubleSequence(longdouble_seq_t, 5, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongDoubleSequence(&longdouble_out, &size_out, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(longdouble_seq_t[i], longdouble_out[i]);
      }

      free(longdouble_out);
  }

  TEST(nanoCDRSequencesTests, StringSequence)
  {
      char ** string_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeStringSequence(string_seq_t, 5, nanoCDRWrite);

      uint32_t size_out;

      // Deseriazliation.
      deserializeStringSequence(&string_out, &size_out, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        int32_t length_in_aux = (uint32_t)std::strlen(string_seq_t[i]);
        int32_t length_out_aux = (uint32_t)std::strlen(string_out[i]);
        int32_t comparative_aux = std::strcmp(string_seq_t[i], string_out[i]);
        EXPECT_EQ(length_in_aux, length_out_aux);
        EXPECT_EQ(comparative_aux, 0);
        free(string_out[i]);
      }
      free(string_out);
  }

  TEST(nanoCDRTests, SimpleVar)
  {
    char char_out;
    signed char octect_out;
    int16_t short_out;
    uint16_t ushort_out;
    int32_t long_out;
    uint32_t ulong_out;
    int64_t longlong_out;
    uint64_t ulonglong_out;
    long long longlonglong_out;
    unsigned long long ulonglonglong_out;
    float float_out;
    double double_out;
    long double longdouble_out;
    char * string_out;
    char * string_out_2;

    char buffer[BUFFER_LENGTH];
    struct nanoBuffer * nanoBuffer = NULL;
    struct nanoCDR * nanoCDRWrite = NULL;
    struct nanoCDR * nanoCDRRead = NULL;

    // Check good case.
    newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
    newNanoCDR(&nanoCDRWrite, nanoBuffer);
    newNanoCDR(&nanoCDRRead, nanoBuffer);

    const uint32_t length = (uint32_t)std::strlen(string_t);
    uint32_t length_out;

    const uint32_t length_2 = (uint32_t)std::strlen(emptystring_t);
    uint32_t length_out_2;

    // Serialization.
    serializeChar(char_t, nanoCDRWrite);
    serializeSignedChar(octet_t, nanoCDRWrite);
    serializeShort(short_t, nanoCDRWrite);
    serializeUnsignedShort(ushort_t, nanoCDRWrite);
    serializeInt(long_t, nanoCDRWrite);
    serializeUnsignedInt(ulong_t, nanoCDRWrite);
    serializeLong(longlong_t, nanoCDRWrite);
    serializeUnsignedLong(ulonglong_t, nanoCDRWrite);
    serializeLongLong(longlonglong_t, nanoCDRWrite);
    serializeUnsignedLongLong(ulonglonglong_t, nanoCDRWrite);
    serializeFloat(float_tt, nanoCDRWrite);
    serializeDouble(double_tt, nanoCDRWrite);
    serializeLongDouble(longdouble_t, nanoCDRWrite);
    serializeString(string_t, length, nanoCDRWrite);
    serializeString(emptystring_t, length_2, nanoCDRWrite);

    // Deseriazliation.
    deserializeChar(&char_out, nanoCDRRead);
    deserializeSignedChar(&octect_out, nanoCDRRead);
    deserializeShort(&short_out, nanoCDRRead);
    deserializeUnsignedShort(&ushort_out, nanoCDRRead);
    deserializeInt(&long_out, nanoCDRRead);
    deserializeUnsignedInt(&ulong_out, nanoCDRRead);
    deserializeLong(&longlong_out, nanoCDRRead);
    deserializeUnsignedLong(&ulonglong_out, nanoCDRRead);
    deserializeLongLong(&longlonglong_out, nanoCDRRead);
    deserializeUnsignedLongLong(&ulonglonglong_out, nanoCDRRead);
    deserializeFloat(&float_out, nanoCDRRead);
    deserializeDouble(&double_out, nanoCDRRead);
    deserializeLongDouble(&longdouble_out, nanoCDRRead);
    deserializeString(&string_out, &length_out, nanoCDRRead);
    deserializeString(&string_out_2, &length_out_2, nanoCDRRead);

    uint32_t comparative = std::strcmp(string_out, string_t);
    uint32_t comparative_2 = std::strcmp(string_out_2, emptystring_t);

    EXPECT_EQ(char_out, char_t);
    EXPECT_EQ(octect_out, octet_t);
    EXPECT_EQ(short_out, short_t);
    EXPECT_EQ(ushort_out, ushort_t);
    EXPECT_EQ(long_out, long_t);
    EXPECT_EQ(ulong_out, ulong_t);
    EXPECT_EQ(longlong_out, longlong_t);
    EXPECT_EQ(ulonglong_out, ulonglong_t);
    EXPECT_EQ(longlonglong_out, longlonglong_t);
    EXPECT_EQ(ulonglonglong_out, ulonglonglong_t);
    EXPECT_EQ(float_out, float_tt);
    EXPECT_EQ(double_out, double_tt);
    EXPECT_EQ(longdouble_out, longdouble_t);
    EXPECT_EQ(comparative, 0);
    EXPECT_EQ(length, length_out);
    EXPECT_EQ(comparative_2, 0);
    EXPECT_EQ(length_2, length_out_2);
  }

  TEST(nanoCDRTests, Arrays)
  {
    int32_t i;
    char * char_out;
    unsigned char * uchar_out;
    int16_t * short_out;
    uint16_t * ushort_out;
    int32_t * int_out;
    uint32_t * uint_out;
    int64_t * long_out;
    uint64_t * ulong_out;
    long long * longlong_out;
    unsigned long long * ulonglong_out;
    float * float_out;
    double * double_out;
    long double * longdouble_out;
    char ** string_out;


    char buffer[BUFFER_LENGTH];
    struct nanoBuffer * nanoBuffer = NULL;
    struct nanoCDR * nanoCDRWrite = NULL;
    struct nanoCDR * nanoCDRRead = NULL;

    // Check good case.
    newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
    newNanoCDR(&nanoCDRWrite, nanoBuffer);
    newNanoCDR(&nanoCDRRead, nanoBuffer);

    int16_t result = 0;

    // Serialization.
    result += serializeCharArray(char_array_t, 5, nanoCDRWrite); //5
    result += serializeUnsignedCharArray(octet_array_t, 5, nanoCDRWrite); //5
    result += serializeShortArray(short_array_t, 5, nanoCDRWrite); //10
    result += serializeUnsignedShortArray(ushort_array_t, 5, nanoCDRWrite); //10
    result += serializeIntArray(long_array_t, 5, nanoCDRWrite); //20
    result += serializeUnsignedIntArray(ulong_array_t, 5, nanoCDRWrite); //20
    result += serializeLongArray(longlong_array_t, 5, nanoCDRWrite); //20
    result += serializeUnsignedLongArray(ulonglong_array_t, 5, nanoCDRWrite); //20
    result += serializeLongLongArray(longlonglong_array_t, 5, nanoCDRWrite); //20
    result += serializeUnsignedLongLongArray(ulonglonglong_array_t, 5, nanoCDRWrite); //20
    result += serializeFloatArray(float_array_t, 5, nanoCDRWrite); //20
    result += serializeDoubleArray(double_array_t, 5, nanoCDRWrite); //40
    result += serializeLongDoubleArray(longdouble_array_t, 5, nanoCDRWrite); //40
    result += serializeStringArray(string_seq_t, 5, nanoCDRWrite);

    //uint32_t serialized = getSerializedDataLength();

    EXPECT_EQ(result, 0);
    //EXPECT_EQ(serialized, 130);

    if(result == 0){
      // Deseriazliation.
      result += deserializeCharArray(&char_out, 5, nanoCDRRead);
      result += deserializeUnsignedCharArray(&uchar_out, 5, nanoCDRRead);
      result += deserializeShortArray(&short_out, 5, nanoCDRRead);
      result += deserializeUnsignedShortArray(&ushort_out, 5, nanoCDRRead);
      result += deserializeIntArray(&int_out, 5, nanoCDRRead);
      result += deserializeUnsignedIntArray(&uint_out, 5, nanoCDRRead);
      result += deserializeLongArray(&long_out, 5, nanoCDRRead);
      result += deserializeUnsignedLongArray(&ulong_out, 5, nanoCDRRead);
      result += deserializeLongLongArray(&longlong_out, 5, nanoCDRRead);
      result += deserializeUnsignedLongLongArray(&ulonglong_out, 5, nanoCDRRead);
      result += deserializeFloatArray(&float_out, 5, nanoCDRRead);
      result += deserializeDoubleArray(&double_out, 5, nanoCDRRead);
      result += deserializeLongDoubleArray(&longdouble_out, 5, nanoCDRRead);
      result += deserializeStringArray(&string_out, 5, nanoCDRRead);

      EXPECT_EQ(result, 0);

      if(result == 0){
        for(i = 0; i < 5; i++){
          EXPECT_EQ(char_array_t[i], char_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(octet_array_t[i], uchar_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(short_array_t[i], short_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ushort_array_t[i], ushort_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(long_array_t[i], int_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulong_array_t[i], uint_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(longlong_array_t[i], long_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulonglong_array_t[i], ulong_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(longlonglong_array_t[i], longlong_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulonglonglong_array_t[i], ulonglong_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(float_array_t[i], float_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(double_array_t[i], double_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(longdouble_array_t[i], longdouble_out[i]);
        }
        for(i = 0; i < 5; i++)
        {
          int32_t length_in_aux = (uint32_t)std::strlen(string_seq_t[i]);
          int32_t length_out_aux = (uint32_t)std::strlen(string_out[i]);
          int32_t comparative_aux = std::strcmp(string_seq_t[i], string_out[i]);
          EXPECT_EQ(length_in_aux, length_out_aux);
          EXPECT_EQ(comparative_aux, 0);
          free(string_out[i]);
        }

        free(char_out);
        free(uchar_out);
        free(short_out);
        free(ushort_out);
        free(int_out);
        free(uint_out);
        free(long_out);
        free(ulong_out);
        free(longlong_out);
        free(ulonglong_out);
        free(float_out);
        free(double_out);
        free(longdouble_out);
        free(string_out);
      }
    }
  }

  TEST(nanoCDRTests, Sequences)
  {
    int32_t i;
    char * char_out;
    uint32_t char_out_size;
    unsigned char * uchar_out;
    uint32_t uchar_out_size;
    int16_t * short_out;
    uint32_t short_out_size;
    uint16_t * ushort_out;
    uint32_t ushort_out_size;
    int32_t * int_out;
    uint32_t int_out_size;
    uint32_t * uint_out;
    uint32_t uint_out_size;
    int64_t * long_out;
    uint32_t long_out_size;
    uint64_t * ulong_out;
    uint32_t ulong_out_size;
    long long * longlong_out;
    uint32_t longlong_out_size;
    unsigned long long * ulonglong_out;
    uint32_t ulonglong_out_size;
    float * float_out;
    uint32_t float_out_size;
    double * double_out;
    uint32_t double_out_size;
    long double * longdouble_out;
    uint32_t longdouble_out_size;
    char ** string_out;
    uint32_t string_out_size;

    int16_t result = 0;


    char buffer[BUFFER_LENGTH];
    struct nanoBuffer * nanoBuffer = NULL;
    struct nanoCDR * nanoCDRWrite = NULL;
    struct nanoCDR * nanoCDRRead = NULL;

    // Check good case.
    newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
    newNanoCDR(&nanoCDRWrite, nanoBuffer);
    newNanoCDR(&nanoCDRRead, nanoBuffer);

    // Serialization.
    result += serializeCharSequence(char_seq_t, 5, nanoCDRWrite); //9
    result += serializeUnsignedCharSequence(octet_seq_t, 5, nanoCDRWrite); //9
    result += serializeShortSequence(short_seq_t, 5, nanoCDRWrite);//14
    result += serializeUnsignedShortSequence(ushort_seq_t, 5, nanoCDRWrite);//14
    result += serializeIntSequence(long_seq_t, 5, nanoCDRWrite);//24
    result += serializeUnsignedIntSequence(ulong_seq_t, 5, nanoCDRWrite);//24
    result += serializeLongSequence(longlong_seq_t, 5, nanoCDRWrite);//24
    result += serializeUnsignedLongSequence(ulonglong_seq_t, 5, nanoCDRWrite);//24
    result += serializeLongLongSequence(longlonglong_seq_t, 5, nanoCDRWrite);//24
    result += serializeUnsignedLongLongSequence(ulonglonglong_seq_t, 5, nanoCDRWrite);//24
    result += serializeFloatSequence(float_seq_t, 5, nanoCDRWrite);//24
    result += serializeDoubleSequence(double_seq_t, 5, nanoCDRWrite);//44
    result += serializeLongDoubleSequence(longdouble_seq_t, 5, nanoCDRWrite);//44
    result += serializeStringSequence(string_seq_t, 5, nanoCDRWrite);

    //uint32_t serialized = getSerializedDataLength();
    //EXPECT_EQ(serialized, 162);

    EXPECT_EQ(result, 0);

    if(result == 0){
      // Deseriazliation.
      result += deserializeCharSequence(&char_out, &char_out_size, nanoCDRRead);
      result += deserializeUnsignedCharSequence(&uchar_out, &uchar_out_size, nanoCDRRead);
      result += deserializeShortSequence(&short_out, &short_out_size, nanoCDRRead);
      result += deserializeUnsignedShortSequence(&ushort_out, &ushort_out_size, nanoCDRRead);
      result += deserializeIntSequence(&int_out, &int_out_size, nanoCDRRead);
      result += deserializeUnsignedIntSequence(&uint_out, &uint_out_size, nanoCDRRead);
      result += deserializeLongSequence(&long_out, &long_out_size, nanoCDRRead);
      result += deserializeUnsignedLongSequence(&ulong_out, &ulong_out_size, nanoCDRRead);
      result += deserializeLongLongSequence(&longlong_out, &longlong_out_size, nanoCDRRead);
      result += deserializeUnsignedLongLongSequence(&ulonglong_out, &ulonglong_out_size, nanoCDRRead);
      result += deserializeFloatSequence(&float_out, &float_out_size, nanoCDRRead);
      result += deserializeDoubleSequence(&double_out, &double_out_size, nanoCDRRead);
      result += deserializeLongDoubleSequence(&longdouble_out, &longdouble_out_size, nanoCDRRead);
      result += deserializeStringSequence(&string_out, &string_out_size, nanoCDRRead);

      EXPECT_EQ(result, 0);

      if(result == 0){
        EXPECT_EQ(char_out_size, 5);
        EXPECT_EQ(uchar_out_size, 5);
        EXPECT_EQ(short_out_size, 5);
        EXPECT_EQ(ushort_out_size, 5);
        EXPECT_EQ(int_out_size, 5);
        EXPECT_EQ(uint_out_size, 5);
        EXPECT_EQ(long_out_size, 5);
        EXPECT_EQ(ulong_out_size, 5);
        EXPECT_EQ(longlong_out_size, 5);
        EXPECT_EQ(ulonglong_out_size, 5);
        EXPECT_EQ(float_out_size, 5);
        EXPECT_EQ(double_out_size, 5);
        EXPECT_EQ(longdouble_out_size, 5);
        EXPECT_EQ(string_out_size, 5);

        for(i = 0; i < 5; i++){
          EXPECT_EQ(char_seq_t[i], char_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(octet_seq_t[i], uchar_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(short_seq_t[i], short_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ushort_seq_t[i], ushort_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(long_seq_t[i], int_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulong_seq_t[i], uint_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(longlong_seq_t[i], long_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulonglong_seq_t[i], ulong_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(longlonglong_seq_t[i], longlong_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulonglonglong_seq_t[i], ulonglong_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(float_seq_t[i], float_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(double_seq_t[i], double_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(longdouble_seq_t[i], longdouble_out[i]);
        }
        for(i = 0; i < 5; i++)
        {
          int32_t length_in_aux = (uint32_t)std::strlen(string_seq_t[i]);
          int32_t length_out_aux = (uint32_t)std::strlen(string_out[i]);
          int32_t comparative_aux = std::strcmp(string_seq_t[i], string_out[i]);
          EXPECT_EQ(length_in_aux, length_out_aux);
          EXPECT_EQ(comparative_aux, 0);
          free(string_out[i]);
        }

        free(char_out);
        free(uchar_out);
        free(short_out);
        free(ushort_out);
        free(int_out);
        free(uint_out);
        free(long_out);
        free(ulong_out);
        free(longlong_out);
        free(ulonglong_out);
        free(float_out);
        free(double_out);
        free(longdouble_out);
        free(string_out);
      }
    }
  }

  TEST(nanoCDRTests, All)
  {
    //SIMPLE
    char char_out;
    signed char octect_out;
    int16_t short_out;
    uint16_t ushort_out;
    int32_t long_out;
    uint32_t ulong_out;
    int64_t longlong_out;
    uint64_t ulonglong_out;
    long long longlonglong_out;
    unsigned long long ulonglonglong_out;
    float float_out;
    double double_out;
    long double longdouble_out;
    char * string_out;
    char * string_out_2;

    //ARRAYS
    int32_t i;
    char * char_array_out;
    unsigned char * uchar_array_out;
    int16_t * short_array_out;
    uint16_t * ushort_array_out;
    int32_t * int_array_out;
    uint32_t * uint_array_out;
    int64_t * long_array_out;
    uint64_t * ulong_array_out;
    long long * longlong_array_out;
    unsigned long long * ulonglong_array_out;
    float * float_array_out;
    double * double_array_out;
    long double * longdouble_array_out;
    char ** string_array_out;

    //SEQUENCES
    char * char_seq_out;
    uint32_t char_out_size;
    unsigned char * uchar_seq_out;
    uint32_t uchar_out_size;
    int16_t * short_seq_out;
    uint32_t short_out_size;
    uint16_t * ushort_seq_out;
    uint32_t ushort_out_size;
    int32_t * int_seq_out;
    uint32_t int_out_size;
    uint32_t * uint_seq_out;
    uint32_t uint_out_size;
    int64_t * long_seq_out;
    uint32_t long_out_size;
    uint64_t * ulong_seq_out;
    uint32_t ulong_out_size;
    long long * longlong_seq_out;
    uint32_t longlong_out_size;
    unsigned long long * ulonglong_seq_out;
    uint32_t ulonglong_out_size;
    float * float_seq_out;
    uint32_t float_out_size;
    double * double_seq_out;
    uint32_t double_out_size;
    long double * longdouble_seq_out;
    uint32_t longdouble_out_size;
    char ** string_seq_out;
    uint32_t string_out_size;


    char buffer[BUFFER_LENGTH];
    struct nanoBuffer * nanoBuffer = NULL;
    struct nanoCDR * nanoCDRWrite = NULL;
    struct nanoCDR * nanoCDRRead = NULL;

    // Check good case.
    newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
    newNanoCDR(&nanoCDRWrite, nanoBuffer);
    newNanoCDR(&nanoCDRRead, nanoBuffer);

    const uint32_t length = (uint32_t)std::strlen(string_t);
    uint32_t length_out;

    int16_t result = 0;

    const uint32_t length_2 = (uint32_t)std::strlen(emptystring_t);
    uint32_t length_out_2;

    // Serialization.
    result += serializeChar(char_t, nanoCDRWrite);
    result += serializeSignedChar(octet_t, nanoCDRWrite);
    result += serializeShort(short_t, nanoCDRWrite);
    result += serializeUnsignedShort(ushort_t, nanoCDRWrite);
    result += serializeInt(long_t, nanoCDRWrite);
    result += serializeUnsignedInt(ulong_t, nanoCDRWrite);
    result += serializeLong(longlong_t, nanoCDRWrite);
    result += serializeUnsignedLong(ulonglong_t, nanoCDRWrite);
    result += serializeLongLong(longlonglong_t, nanoCDRWrite);
    result += serializeUnsignedLongLong(ulonglonglong_t, nanoCDRWrite);
    result += serializeFloat(float_tt, nanoCDRWrite);
    result += serializeDouble(double_tt, nanoCDRWrite);
    result += serializeLongDouble(longdouble_t, nanoCDRWrite);
    result += serializeString(string_t, length, nanoCDRWrite);
    result += serializeString(emptystring_t, length_2, nanoCDRWrite);

    result += serializeCharArray(char_array_t, 5, nanoCDRWrite); //5
    result += serializeUnsignedCharArray(octet_array_t, 5, nanoCDRWrite); //5
    result += serializeShortArray(short_array_t, 5, nanoCDRWrite); //10
    result += serializeUnsignedShortArray(ushort_array_t, 5, nanoCDRWrite); //10
    result += serializeIntArray(long_array_t, 5, nanoCDRWrite); //20
    result += serializeUnsignedIntArray(ulong_array_t, 5, nanoCDRWrite); //20

    result += serializeLongArray(longlong_array_t, 5, nanoCDRWrite);
    result += serializeUnsignedLongArray(ulonglong_array_t, 5, nanoCDRWrite);
    result += serializeLongLongArray(longlonglong_array_t, 5, nanoCDRWrite);
    result += serializeUnsignedLongLongArray(ulonglonglong_array_t, 5, nanoCDRWrite);

    result += serializeFloatArray(float_array_t, 5, nanoCDRWrite); //20
    result += serializeDoubleArray(double_array_t, 5, nanoCDRWrite); //40
    result += serializeLongDoubleArray(longdouble_array_t, 5, nanoCDRWrite);
    result += serializeStringArray(string_seq_t, 5, nanoCDRWrite);

    result += serializeCharSequence(char_seq_t, 5, nanoCDRWrite); //9
    result += serializeUnsignedCharSequence(octet_seq_t, 5, nanoCDRWrite); //9
    result += serializeShortSequence(short_seq_t, 5, nanoCDRWrite);//14
    result += serializeUnsignedShortSequence(ushort_seq_t, 5, nanoCDRWrite);//14
    result += serializeIntSequence(long_seq_t, 5, nanoCDRWrite);//24
    result += serializeUnsignedIntSequence(ulong_seq_t, 5, nanoCDRWrite);//24

    result += serializeLongSequence(longlong_seq_t, 5, nanoCDRWrite);
    result += serializeUnsignedLongSequence(ulonglong_seq_t, 5, nanoCDRWrite);
    result += serializeLongLongSequence(longlonglong_seq_t, 5, nanoCDRWrite);
    result += serializeUnsignedLongLongSequence(ulonglonglong_seq_t, 5, nanoCDRWrite);

    result += serializeFloatSequence(float_seq_t, 5, nanoCDRWrite);//24
    result += serializeDoubleSequence(double_seq_t, 5, nanoCDRWrite);//44
    result += serializeLongDoubleSequence(longdouble_seq_t, 5, nanoCDRWrite);//44
    result += serializeStringSequence(string_seq_t, 5, nanoCDRWrite);

    //uint32_t serialized = getSerializedDataLength();
    //EXPECT_EQ(serialized, 357);
    EXPECT_EQ(result, 0);

    if(result == 0){
    // Deseriazliation.
      result += deserializeChar(&char_out, nanoCDRRead);
      result += deserializeSignedChar(&octect_out, nanoCDRRead);
      result += deserializeShort(&short_out, nanoCDRRead);
      result += deserializeUnsignedShort(&ushort_out, nanoCDRRead);
      result += deserializeInt(&long_out, nanoCDRRead);
      result += deserializeUnsignedInt(&ulong_out, nanoCDRRead);
      result += deserializeLong(&longlong_out, nanoCDRRead);
      result += deserializeUnsignedLong(&ulonglong_out, nanoCDRRead);
      result += deserializeLongLong(&longlonglong_out, nanoCDRRead);
      result += deserializeUnsignedLongLong(&ulonglonglong_out, nanoCDRRead);
      result += deserializeFloat(&float_out, nanoCDRRead);
      result += deserializeDouble(&double_out, nanoCDRRead);
      result += deserializeLongDouble(&longdouble_out, nanoCDRRead);
      result += deserializeString(&string_out, &length_out, nanoCDRRead);
      result += deserializeString(&string_out_2, &length_out_2, nanoCDRRead);

      result += deserializeCharArray(&char_array_out, 5, nanoCDRRead);
      result += deserializeUnsignedCharArray(&uchar_array_out, 5, nanoCDRRead);
      result += deserializeShortArray(&short_array_out, 5, nanoCDRRead);
      result += deserializeUnsignedShortArray(&ushort_array_out, 5, nanoCDRRead);
      result += deserializeIntArray(&int_array_out, 5, nanoCDRRead);
      result += deserializeUnsignedIntArray(&uint_array_out, 5, nanoCDRRead);

      result += deserializeLongArray(&long_array_out, 5, nanoCDRRead);
      result += deserializeUnsignedLongArray(&ulong_array_out, 5, nanoCDRRead);
      result += deserializeLongLongArray(&longlong_array_out, 5, nanoCDRRead);
      result += deserializeUnsignedLongLongArray(&ulonglong_array_out, 5, nanoCDRRead);

      result += deserializeFloatArray(&float_array_out, 5, nanoCDRRead);
      result += deserializeDoubleArray(&double_array_out, 5, nanoCDRRead);
      result += deserializeLongDoubleArray(&longdouble_array_out, 5, nanoCDRRead);
      result += deserializeStringArray(&string_array_out, 5, nanoCDRRead);

      result += deserializeCharSequence(&char_seq_out, &char_out_size, nanoCDRRead);
      result += deserializeUnsignedCharSequence(&uchar_seq_out, &uchar_out_size, nanoCDRRead);
      result += deserializeShortSequence(&short_seq_out, &short_out_size, nanoCDRRead);
      result += deserializeUnsignedShortSequence(&ushort_seq_out, &ushort_out_size, nanoCDRRead);
      result += deserializeIntSequence(&int_seq_out, &int_out_size, nanoCDRRead);
      result += deserializeUnsignedIntSequence(&uint_seq_out, &uint_out_size, nanoCDRRead);

      result += deserializeLongSequence(&long_seq_out, &long_out_size, nanoCDRRead);
      result += deserializeUnsignedLongSequence(&ulong_seq_out, &ulong_out_size, nanoCDRRead);
      result += deserializeLongLongSequence(&longlong_seq_out, &longlong_out_size, nanoCDRRead);
      result += deserializeUnsignedLongLongSequence(&ulonglong_seq_out, &ulonglong_out_size, nanoCDRRead);

      result += deserializeFloatSequence(&float_seq_out, &float_out_size, nanoCDRRead);
      result += deserializeDoubleSequence(&double_seq_out, &double_out_size, nanoCDRRead);
      result += deserializeLongDoubleSequence(&longdouble_seq_out, &longdouble_out_size, nanoCDRRead);
      result += deserializeStringSequence(&string_seq_out, &string_out_size, nanoCDRRead);

      EXPECT_EQ(result, 0);

      if(result == 0)
      {
        uint32_t comparative = (uint32_t)std::strcmp(string_out, string_t);
        uint32_t comparative_2 = (uint32_t)std::strcmp(string_out_2, emptystring_t);

        EXPECT_EQ(char_out, char_t);
        EXPECT_EQ(octect_out, octet_t);
        EXPECT_EQ(short_out, short_t);
        EXPECT_EQ(ushort_out, ushort_t);
        EXPECT_EQ(long_out, long_t);
        EXPECT_EQ(ulong_out, ulong_t);
        EXPECT_EQ(longlong_out, longlong_t);
        EXPECT_EQ(ulonglong_out, ulonglong_t);
        EXPECT_EQ(longlonglong_out, longlonglong_t);
        EXPECT_EQ(ulonglonglong_out, ulonglonglong_t);
        EXPECT_EQ(float_out, float_tt);
        EXPECT_EQ(double_out, double_tt);
        EXPECT_EQ(longdouble_out, longdouble_t);
        EXPECT_EQ(comparative, 0);
        EXPECT_EQ(length, length_out);
        EXPECT_EQ(comparative_2, 0);
        EXPECT_EQ(length_2, length_out_2);

        for(i = 0; i < 5; i++){
          EXPECT_EQ(char_array_t[i], char_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(octet_array_t[i], uchar_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(short_array_t[i], short_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ushort_array_t[i], ushort_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(long_array_t[i], int_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulong_array_t[i], uint_array_out[i]);
        }

        for(i = 0; i < 5; i++){
          EXPECT_EQ(longlong_array_t[i], long_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulonglong_array_t[i], ulong_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(longlonglong_array_t[i], longlong_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulonglonglong_array_t[i], ulonglong_array_out[i]);
        }

        for(i = 0; i < 5; i++){
          EXPECT_EQ(float_array_t[i], float_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(double_array_t[i], double_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(longdouble_array_t[i], longdouble_array_out[i]);
        }
        for(i = 0; i < 5; i++)
        {
          int32_t length_in_aux = (uint32_t)std::strlen(string_seq_t[i]);
          int32_t length_out_aux = (uint32_t)std::strlen(string_array_out[i]);
          int32_t comparative_aux = std::strcmp(string_seq_t[i], string_array_out[i]);
          EXPECT_EQ(length_in_aux, length_out_aux);
          EXPECT_EQ(comparative_aux, 0);
          free(string_array_out[i]);
        }
        free(string_array_out);

        EXPECT_EQ(char_out_size, 5);
        EXPECT_EQ(uchar_out_size, 5);
        EXPECT_EQ(short_out_size, 5);
        EXPECT_EQ(ushort_out_size, 5);
        EXPECT_EQ(int_out_size, 5);
        EXPECT_EQ(uint_out_size, 5);

        EXPECT_EQ(long_out_size, 5);
        EXPECT_EQ(ulong_out_size, 5);
        EXPECT_EQ(longlong_out_size, 5);
        EXPECT_EQ(ulonglong_out_size, 5);

        EXPECT_EQ(float_out_size, 5);
        EXPECT_EQ(double_out_size, 5);
        EXPECT_EQ(longdouble_out_size, 5);
        EXPECT_EQ(string_out_size, 5);

        for(i = 0; i < 5; i++){
          EXPECT_EQ(char_seq_t[i], char_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(octet_seq_t[i], uchar_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(short_seq_t[i], short_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ushort_seq_t[i], ushort_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(long_seq_t[i], int_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulong_seq_t[i], uint_seq_out[i]);
        }

        for(i = 0; i < 5; i++){
          EXPECT_EQ(longlong_seq_t[i], long_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulonglong_seq_t[i], ulong_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(longlonglong_seq_t[i], longlong_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulonglonglong_seq_t[i], ulonglong_seq_out[i]);
        }

        for(i = 0; i < 5; i++){
          EXPECT_EQ(float_seq_t[i], float_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(double_seq_t[i], double_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(longdouble_seq_t[i], longdouble_seq_out[i]);
        }

        for(i = 0; i < 5; i++)
        {
          int32_t length_in_aux = (uint32_t)std::strlen(string_seq_t[i]);
          int32_t length_out_aux = (uint32_t)std::strlen(string_seq_out[i]);
          int32_t comparative_aux = std::strcmp(string_seq_t[i], string_seq_out[i]);
          EXPECT_EQ(length_in_aux, length_out_aux);
          EXPECT_EQ(comparative_aux, 0);
          free(string_seq_out[i]);
        }
        free(string_seq_out);

        free(char_array_out);
        free(uchar_array_out);
        free(short_array_out);
        free(ushort_array_out);
        free(int_array_out);
        free(uint_array_out);

        free(long_array_out);
        free(ulong_array_out);
        free(longlong_array_out);
        free(ulonglong_array_out);

        free(float_array_out);
        free(double_array_out);
        free(longdouble_array_out);

        free(char_seq_out);
        free(uchar_seq_out);
        free(short_seq_out);
        free(ushort_seq_out);
        free(int_seq_out);
        free(uint_seq_out);

        free(long_seq_out);
        free(ulong_seq_out);
        free(longlong_seq_out);
        free(ulonglong_seq_out);

        free(float_seq_out);
        free(double_seq_out);
        free(longdouble_seq_out);
      }
    }
  }

  TEST(nanoCDRTests, AllEndianness)
  {
    //SIMPLE
    char char_out;
    signed char octect_out;
    int16_t short_out;
    uint16_t ushort_out;
    int32_t long_out;
    uint32_t ulong_out;
    int64_t longlong_out;
    uint64_t ulonglong_out;
    long long longlonglong_out;
    unsigned long long ulonglonglong_out;
    float float_out;
    double double_out;
    long double longdouble_out;
    char * string_out;
    char * string_out_2;

    //ARRAYS
    int32_t i;
    char * char_array_out;
    unsigned char * uchar_array_out;
    int16_t * short_array_out;
    uint16_t * ushort_array_out;
    int32_t * int_array_out;
    uint32_t * uint_array_out;
    int64_t * long_array_out;
    uint64_t * ulong_array_out;
    long long * longlong_array_out;
    unsigned long long * ulonglong_array_out;
    float * float_array_out;
    double * double_array_out;
    long double * longdouble_array_out;
    char ** string_array_out;

    //SEQUENCES
    char * char_seq_out;
    uint32_t char_out_size;
    unsigned char * uchar_seq_out;
    uint32_t uchar_out_size;
    int16_t * short_seq_out;
    uint32_t short_out_size;
    uint16_t * ushort_seq_out;
    uint32_t ushort_out_size;
    int32_t * int_seq_out;
    uint32_t int_out_size;
    uint32_t * uint_seq_out;
    uint32_t uint_out_size;
    int64_t * long_seq_out;
    uint32_t long_out_size;
    uint64_t * ulong_seq_out;
    uint32_t ulong_out_size;
    long long * longlong_seq_out;
    uint32_t longlong_out_size;
    unsigned long long * ulonglong_seq_out;
    uint32_t ulonglong_out_size;
    float * float_seq_out;
    uint32_t float_out_size;
    double * double_seq_out;
    uint32_t double_out_size;
    long double * longdouble_seq_out;
    uint32_t longdouble_out_size;
    char ** string_seq_out;
    uint32_t string_out_size;


    char buffer[BUFFER_LENGTH];
    struct nanoBuffer * nanoBuffer = NULL;
    struct nanoCDR * nanoCDRWrite = NULL;
    struct nanoCDR * nanoCDRRead = NULL;

    // Check good case.
    newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
    newNanoCDR(&nanoCDRWrite, nanoBuffer);
    newNanoCDR(&nanoCDRRead, nanoBuffer);

    const uint32_t length = (uint32_t)std::strlen(string_t);
    uint32_t length_out;

    int16_t result = 0;

    const uint32_t length_2 = (uint32_t)std::strlen(emptystring_t);
    uint32_t length_out_2;

    // Serialization.
    result += serializeChar(char_t, nanoCDRWrite);
    result += serializeSignedChar(octet_t, nanoCDRWrite);
    result += serializeShortEndianness(short_t, endianness, nanoCDRWrite);
    result += serializeUnsignedShortEndianness(ushort_t, endianness, nanoCDRWrite);
    result += serializeIntEndianness(long_t, endianness, nanoCDRWrite);
    result += serializeUnsignedIntEndianness(ulong_t, endianness, nanoCDRWrite);
    result += serializeLongEndianness(longlong_t, endianness, nanoCDRWrite);
    result += serializeUnsignedLongEndianness(ulonglong_t, endianness, nanoCDRWrite);
    result += serializeLongLongEndianness(longlonglong_t, endianness, nanoCDRWrite);
    result += serializeUnsignedLongLongEndianness(ulonglonglong_t, endianness, nanoCDRWrite);
    result += serializeFloatEndianness(float_tt, endianness, nanoCDRWrite);
    result += serializeDoubleEndianness(double_tt, endianness, nanoCDRWrite);
    result += serializeLongDoubleEndianness(longdouble_t, endianness, nanoCDRWrite);
    result += serializeStringEndianness(string_t, length, endianness, nanoCDRWrite);
    result += serializeStringEndianness(emptystring_t, length_2, endianness, nanoCDRWrite);

    result += serializeCharArray(char_array_t, 5, nanoCDRWrite); //5
    result += serializeUnsignedCharArray(octet_array_t, 5, nanoCDRWrite); //5
    result += serializeShortArrayEndianness(short_array_t, 5, endianness, nanoCDRWrite); //10
    result += serializeUnsignedShortArrayEndianness(ushort_array_t, 5, endianness, nanoCDRWrite); //10
    result += serializeIntArrayEndianness(long_array_t, 5, endianness, nanoCDRWrite); //20
    result += serializeUnsignedIntArrayEndianness(ulong_array_t, 5, endianness, nanoCDRWrite); //20

    result += serializeLongArrayEndianness(longlong_array_t, 5, endianness, nanoCDRWrite);
    result += serializeUnsignedLongArrayEndianness(ulonglong_array_t, 5, endianness, nanoCDRWrite);
    result += serializeLongLongArrayEndianness(longlonglong_array_t, 5, endianness, nanoCDRWrite);
    result += serializeUnsignedLongLongArrayEndianness(ulonglonglong_array_t, 5, endianness, nanoCDRWrite);

    result += serializeFloatArrayEndianness(float_array_t, 5, endianness, nanoCDRWrite); //20
    result += serializeDoubleArrayEndianness(double_array_t, 5, endianness, nanoCDRWrite); //40
    result += serializeLongDoubleArrayEndianness(longdouble_array_t, 5, endianness, nanoCDRWrite);
    result += serializeStringArrayEndianness(string_seq_t, 5, endianness, nanoCDRWrite);

    result += serializeCharSequenceEndianness(char_seq_t, 5, endianness, nanoCDRWrite); //9
    result += serializeUnsignedCharSequenceEndianness(octet_seq_t, 5, endianness, nanoCDRWrite); //9
    result += serializeShortSequenceEndianness(short_seq_t, 5, endianness, nanoCDRWrite);//14
    result += serializeUnsignedShortSequenceEndianness(ushort_seq_t, 5, endianness, nanoCDRWrite);//14
    result += serializeIntSequenceEndianness(long_seq_t, 5, endianness, nanoCDRWrite);//24
    result += serializeUnsignedIntSequenceEndianness(ulong_seq_t, 5, endianness, nanoCDRWrite);//24

    result += serializeLongSequenceEndianness(longlong_seq_t, 5, endianness, nanoCDRWrite);
    result += serializeUnsignedLongSequenceEndianness(ulonglong_seq_t, 5, endianness, nanoCDRWrite);
    result += serializeLongLongSequenceEndianness(longlonglong_seq_t, 5, endianness, nanoCDRWrite);
    result += serializeUnsignedLongLongSequenceEndianness(ulonglonglong_seq_t, 5, endianness, nanoCDRWrite);

    result += serializeFloatSequenceEndianness(float_seq_t, 5, endianness, nanoCDRWrite);//24
    result += serializeDoubleSequenceEndianness(double_seq_t, 5, endianness, nanoCDRWrite);//44
    result += serializeLongDoubleSequenceEndianness(longdouble_seq_t, 5, endianness, nanoCDRWrite);//44
    result += serializeStringSequenceEndianness(string_seq_t, 5, endianness, nanoCDRWrite);

    //uint32_t serialized = getSerializedDataLength();
    //EXPECT_EQ(serialized, 357);
    EXPECT_EQ(result, 0);

    if(result == 0){
    // Deseriazliation.
      result += deserializeChar(&char_out, nanoCDRRead);
      result += deserializeSignedChar(&octect_out, nanoCDRRead);
      result += deserializeShortEndianness(&short_out, endianness, nanoCDRRead);
      result += deserializeUnsignedShortEndianness(&ushort_out, endianness, nanoCDRRead);
      result += deserializeIntEndianness(&long_out, endianness, nanoCDRRead);
      result += deserializeUnsignedIntEndianness(&ulong_out, endianness, nanoCDRRead);
      result += deserializeLongEndianness(&longlong_out, endianness, nanoCDRRead);
      result += deserializeUnsignedLongEndianness(&ulonglong_out, endianness, nanoCDRRead);
      result += deserializeLongLongEndianness(&longlonglong_out, endianness, nanoCDRRead);
      result += deserializeUnsignedLongLongEndianness(&ulonglonglong_out, endianness, nanoCDRRead);
      result += deserializeFloatEndianness(&float_out, endianness, nanoCDRRead);
      result += deserializeDoubleEndianness(&double_out, endianness, nanoCDRRead);
      result += deserializeLongDoubleEndianness(&longdouble_out, endianness, nanoCDRRead);
      result += deserializeStringEndianness(&string_out, &length_out, endianness, nanoCDRRead);
      result += deserializeStringEndianness(&string_out_2, &length_out_2, endianness, nanoCDRRead);

      result += deserializeCharArray(&char_array_out, 5, nanoCDRRead);
      result += deserializeUnsignedCharArray(&uchar_array_out, 5, nanoCDRRead);
      result += deserializeShortArrayEndianness(&short_array_out, 5, endianness, nanoCDRRead);
      result += deserializeUnsignedShortArrayEndianness(&ushort_array_out, 5, endianness, nanoCDRRead);
      result += deserializeIntArrayEndianness(&int_array_out, 5, endianness, nanoCDRRead);
      result += deserializeUnsignedIntArrayEndianness(&uint_array_out, 5, endianness, nanoCDRRead);

      result += deserializeLongArrayEndianness(&long_array_out, 5, endianness, nanoCDRRead);
      result += deserializeUnsignedLongArrayEndianness(&ulong_array_out, 5, endianness, nanoCDRRead);
      result += deserializeLongLongArrayEndianness(&longlong_array_out, 5, endianness, nanoCDRRead);
      result += deserializeUnsignedLongLongArrayEndianness(&ulonglong_array_out, 5, endianness, nanoCDRRead);

      result += deserializeFloatArrayEndianness(&float_array_out, 5, endianness, nanoCDRRead);
      result += deserializeDoubleArrayEndianness(&double_array_out, 5, endianness, nanoCDRRead);
      result += deserializeLongDoubleArrayEndianness(&longdouble_array_out, 5, endianness, nanoCDRRead);
      result += deserializeStringArrayEndianness(&string_array_out, 5, endianness, nanoCDRRead);

      result += deserializeCharSequenceEndianness(&char_seq_out, &char_out_size, endianness, nanoCDRRead);
      result += deserializeUnsignedCharSequenceEndianness(&uchar_seq_out, &uchar_out_size, endianness, nanoCDRRead);
      result += deserializeShortSequenceEndianness(&short_seq_out, &short_out_size, endianness, nanoCDRRead);
      result += deserializeUnsignedShortSequenceEndianness(&ushort_seq_out, &ushort_out_size, endianness, nanoCDRRead);
      result += deserializeIntSequenceEndianness(&int_seq_out, &int_out_size, endianness, nanoCDRRead);
      result += deserializeUnsignedIntSequenceEndianness(&uint_seq_out, &uint_out_size, endianness, nanoCDRRead);

      result += deserializeLongSequenceEndianness(&long_seq_out, &long_out_size, endianness, nanoCDRRead);
      result += deserializeUnsignedLongSequenceEndianness(&ulong_seq_out, &ulong_out_size, endianness, nanoCDRRead);
      result += deserializeLongLongSequenceEndianness(&longlong_seq_out, &longlong_out_size, endianness, nanoCDRRead);
      result += deserializeUnsignedLongLongSequenceEndianness(&ulonglong_seq_out, &ulonglong_out_size, endianness, nanoCDRRead);

      result += deserializeFloatSequenceEndianness(&float_seq_out, &float_out_size, endianness, nanoCDRRead);
      result += deserializeDoubleSequenceEndianness(&double_seq_out, &double_out_size, endianness, nanoCDRRead);
      result += deserializeLongDoubleSequenceEndianness(&longdouble_seq_out, &longdouble_out_size, endianness, nanoCDRRead);
      result += deserializeStringSequenceEndianness(&string_seq_out, &string_out_size, endianness, nanoCDRRead);

      EXPECT_EQ(result, 0);

      if(result == 0)
      {
        uint32_t comparative = (uint32_t)std::strcmp(string_out, string_t);
        uint32_t comparative_2 = (uint32_t)std::strcmp(string_out_2, emptystring_t);

        EXPECT_EQ(char_out, char_t);
        EXPECT_EQ(octect_out, octet_t);
        EXPECT_EQ(short_out, short_t);
        EXPECT_EQ(ushort_out, ushort_t);
        EXPECT_EQ(long_out, long_t);
        EXPECT_EQ(ulong_out, ulong_t);
        EXPECT_EQ(longlong_out, longlong_t);
        EXPECT_EQ(ulonglong_out, ulonglong_t);
        EXPECT_EQ(longlonglong_out, longlonglong_t);
        EXPECT_EQ(ulonglonglong_out, ulonglonglong_t);
        EXPECT_EQ(float_out, float_tt);
        EXPECT_EQ(double_out, double_tt);
        EXPECT_EQ(longdouble_out, longdouble_t);
        EXPECT_EQ(comparative, 0);
        EXPECT_EQ(length, length_out);
        EXPECT_EQ(comparative_2, 0);
        EXPECT_EQ(length_2, length_out_2);

        for(i = 0; i < 5; i++){
          EXPECT_EQ(char_array_t[i], char_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(octet_array_t[i], uchar_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(short_array_t[i], short_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ushort_array_t[i], ushort_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(long_array_t[i], int_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulong_array_t[i], uint_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(longlong_array_t[i], long_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulonglong_array_t[i], ulong_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(longlonglong_array_t[i], longlong_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulonglonglong_array_t[i], ulonglong_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(float_array_t[i], float_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(double_array_t[i], double_array_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(longdouble_array_t[i], longdouble_array_out[i]);
        }
        for(i = 0; i < 5; i++)
        {
          int32_t length_in_aux = (uint32_t)std::strlen(string_seq_t[i]);
          int32_t length_out_aux = (uint32_t)std::strlen(string_array_out[i]);
          int32_t comparative_aux = std::strcmp(string_seq_t[i], string_array_out[i]);
          EXPECT_EQ(length_in_aux, length_out_aux);
          EXPECT_EQ(comparative_aux, 0);
          free(string_array_out[i]);
        }
        free(string_array_out);

        EXPECT_EQ(char_out_size, 5);
        EXPECT_EQ(uchar_out_size, 5);
        EXPECT_EQ(short_out_size, 5);
        EXPECT_EQ(ushort_out_size, 5);
        EXPECT_EQ(int_out_size, 5);
        EXPECT_EQ(uint_out_size, 5);

        EXPECT_EQ(long_out_size, 5);
        EXPECT_EQ(ulong_out_size, 5);
        EXPECT_EQ(longlong_out_size, 5);
        EXPECT_EQ(ulonglong_out_size, 5);

        EXPECT_EQ(float_out_size, 5);
        EXPECT_EQ(double_out_size, 5);
        EXPECT_EQ(longdouble_out_size, 5);
        EXPECT_EQ(string_out_size, 5);

        for(i = 0; i < 5; i++){
          EXPECT_EQ(char_seq_t[i], char_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(octet_seq_t[i], uchar_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(short_seq_t[i], short_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ushort_seq_t[i], ushort_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(long_seq_t[i], int_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulong_seq_t[i], uint_seq_out[i]);
        }

        for(i = 0; i < 5; i++){
          EXPECT_EQ(longlong_seq_t[i], long_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulonglong_seq_t[i], ulong_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(longlonglong_seq_t[i], longlong_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(ulonglonglong_seq_t[i], ulonglong_seq_out[i]);
        }

        for(i = 0; i < 5; i++){
          EXPECT_EQ(float_seq_t[i], float_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(double_seq_t[i], double_seq_out[i]);
        }
        for(i = 0; i < 5; i++){
          EXPECT_EQ(longdouble_seq_t[i], longdouble_seq_out[i]);
        }

        for(i = 0; i < 5; i++)
        {
          int32_t length_in_aux = (uint32_t)std::strlen(string_seq_t[i]);
          int32_t length_out_aux = (uint32_t)std::strlen(string_seq_out[i]);
          int32_t comparative_aux = std::strcmp(string_seq_t[i], string_seq_out[i]);
          EXPECT_EQ(length_in_aux, length_out_aux);
          EXPECT_EQ(comparative_aux, 0);
          free(string_seq_out[i]);
        }
        free(string_seq_out);

        free(char_array_out);
        free(uchar_array_out);
        free(short_array_out);
        free(ushort_array_out);
        free(int_array_out);
        free(uint_array_out);

        free(long_array_out);
        free(ulong_array_out);
        free(longlong_array_out);
        free(ulonglong_array_out);

        free(float_array_out);
        free(double_array_out);
        free(longdouble_array_out);

        free(char_seq_out);
        free(uchar_seq_out);
        free(short_seq_out);
        free(ushort_seq_out);
        free(int_seq_out);
        free(uint_seq_out);

        free(long_seq_out);
        free(ulong_seq_out);
        free(longlong_seq_out);
        free(ulonglong_seq_out);

        free(float_seq_out);
        free(double_seq_out);
        free(longdouble_seq_out);
      }
    }
  }

  TEST(nanoCDRBasicEndiannessTests, Short)
  {
      int16_t short_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeShortEndianness(short_t, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeShortEndianness(&short_out, endianness, nanoCDRRead);

      EXPECT_EQ(short_out, short_t);
  }

  TEST(nanoCDRBasicEndiannessTests, UnsignedShort)
  {
      uint16_t ushort_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedShortEndianness(ushort_t, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedShortEndianness(&ushort_out, endianness, nanoCDRRead);

      EXPECT_EQ(ushort_out, ushort_t);
  }


  TEST(nanoCDRBasicEndiannessTests, Int)
  {
      int32_t long_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeIntEndianness(long_t, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeIntEndianness(&long_out, endianness, nanoCDRRead);

      EXPECT_EQ(long_out, long_t);
  }

  TEST(nanoCDRBasicEndiannessTests, UnsignedInt)
  {
      uint32_t ulong_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedIntEndianness(ulong_t, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedIntEndianness(&ulong_out, endianness, nanoCDRRead);

      EXPECT_EQ(ulong_out, ulong_t);
  }

  TEST(nanoCDRBasicEndiannessTests, Long)
  {
      int64_t long_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongEndianness(longlong_t, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongEndianness(&long_out, endianness, nanoCDRRead);

      EXPECT_EQ(long_out, longlong_t);
  }

  TEST(nanoCDRBasicEndiannessTests, uLong)
  {
      uint64_t ulong_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedLongEndianness(ulonglong_t, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedLongEndianness(&ulong_out, endianness, nanoCDRRead);

      EXPECT_EQ(ulong_out, ulonglong_t);
  }

  TEST(nanoCDRBasicEndiannessTests, LongLong)
  {
      long long longlong_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongLongEndianness(longlonglong_t, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongLongEndianness(&longlong_out, endianness, nanoCDRRead);

      EXPECT_EQ(longlong_out, longlonglong_t);
  }

  TEST(nanoCDRBasicEndiannessTests, uLongLong)
  {
      unsigned long long ulonglong_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedLongLongEndianness(ulonglonglong_t, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedLongLongEndianness(&ulonglong_out, endianness, nanoCDRRead);

      EXPECT_EQ(ulonglong_out, ulonglonglong_t);
  }

  TEST(nanoCDRBasicEndiannessTests, Float)
  {
      float float_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeFloatEndianness(float_tt, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeFloatEndianness(&float_out, endianness, nanoCDRRead);

      EXPECT_EQ(float_out, float_tt);
  }

  TEST(nanoCDRBasicEndiannessTests, Double)
  {
      double double_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeDoubleEndianness(double_tt, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeDoubleEndianness(&double_out, endianness, nanoCDRRead);

      EXPECT_EQ(double_out, double_tt);
  }

  TEST(nanoCDRBasicEndiannessTests, LongDouble)
  {
      long double longdouble_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongDoubleEndianness(longdouble_t, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongDoubleEndianness(&longdouble_out, endianness, nanoCDRRead);

      EXPECT_EQ(longdouble_out, longdouble_t);
  }

  TEST(nanoCDRBasicEndiannessTests, String)
  {
      char * string_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      const uint32_t length = (uint32_t)std::strlen(string_t);
      uint32_t length_out;

      // Serialization.
      serializeStringEndianness(string_t, length, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeStringEndianness(&string_out, &length_out, endianness, nanoCDRRead);

      uint32_t comparative = std::strcmp(string_out, string_t);

      EXPECT_EQ(comparative, 0);
      EXPECT_EQ(length, length_out);
      free(string_out);
  }

  TEST(nanoCDRBasicEndiannessTests, EmptyString)
  {
      char * string_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      const uint32_t length = (uint32_t)std::strlen(emptystring_t);
      uint32_t length_out;

      // Serialization.
      serializeStringEndianness(emptystring_t, length, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeStringEndianness(&string_out, &length_out, endianness, nanoCDRRead);

      uint32_t comparative = std::strcmp(string_out, emptystring_t);

      EXPECT_EQ(comparative, 0);
      EXPECT_EQ(length, length_out);
      free(string_out);
  }

  TEST(nanoCDRArrayEndiannessTests, ShortArray)
  {
      int16_t * short_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeShortArrayEndianness(short_array_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeShortArrayEndianness(&short_out, 5, endianness, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(short_array_t[i], short_out[i]);
      }
      free(short_out);
  }

  TEST(nanoCDRArrayEndiannessTests, UnsignedShortArray)
  {
      uint16_t * ushort_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedShortArrayEndianness(ushort_array_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedShortArrayEndianness(&ushort_out, 5, endianness, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(ushort_array_t[i], ushort_out[i]);
      }
      free(ushort_out);
  }

  TEST(nanoCDRArrayEndiannessTests, IntArray)
  {
      int32_t * int_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeIntArrayEndianness(long_array_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeIntArrayEndianness(&int_out, 5, endianness, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(long_array_t[i], int_out[i]);
      }
      free(int_out);
  }

  TEST(nanoCDRArrayEndiannessTests, UnsignedIntArray)
  {
      uint32_t * uint_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedIntArrayEndianness(ulong_array_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedIntArrayEndianness(&uint_out, 5, endianness, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(ulong_array_t[i], uint_out[i]);
      }
      free(uint_out);
  }

  TEST(nanoCDRArrayEndiannessTests, LongArray)
  {
      int64_t * long_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongArrayEndianness(longlong_array_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongArrayEndianness(&long_out, 5, endianness, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(longlong_array_t[i], long_out[i]);
      }
      free(long_out);
  }

  TEST(nanoCDRArrayEndiannessTests, ULongArray)
  {
      uint64_t * ulong_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedLongArrayEndianness(ulonglong_array_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedLongArrayEndianness(&ulong_out, 5, endianness, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(ulonglong_array_t[i], ulong_out[i]);
      }
      free(ulong_out);
  }

  TEST(nanoCDRArrayEndiannessTests, LongLongArray)
  {
      long long * longlong_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongLongArrayEndianness(longlonglong_array_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongLongArrayEndianness(&longlong_out, 5, endianness, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(longlonglong_array_t[i], longlong_out[i]);
      }
      free(longlong_out);
  }

  TEST(nanoCDRArrayEndiannessTests, ULongLongArray)
  {
      unsigned long long * ulonglong_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedLongLongArrayEndianness(ulonglonglong_array_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedLongLongArrayEndianness(&ulonglong_out, 5, endianness, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(ulonglonglong_array_t[i], ulonglong_out[i]);
      }
      free(ulonglong_out);
  }

  TEST(nanoCDRArrayEndiannessTests, FloatArray)
  {
      float * float_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeFloatArrayEndianness(float_array_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeFloatArrayEndianness(&float_out, 5, endianness, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(float_array_t[i], float_out[i]);
      }
      free(float_out);
  }

  TEST(nanoCDRArrayEndiannessTests, DoubleArray)
  {
      double * double_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeDoubleArrayEndianness(double_array_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeDoubleArrayEndianness(&double_out, 5, endianness, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(double_array_t[i], double_out[i]);
      }

      free(double_out);
  }

  TEST(nanoCDRArrayEndiannessTests, LongDoubleArray)
  {
      long double * longdouble_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongDoubleArrayEndianness(longdouble_array_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongDoubleArrayEndianness(&longdouble_out, 5, endianness, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(longdouble_array_t[i], longdouble_out[i]);
      }
      free(longdouble_out);
  }

  TEST(nanoCDRArrayEndiannessTests, StringArray)
  {
      char ** string_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeStringArrayEndianness(string_seq_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeStringArrayEndianness(&string_out, 5, endianness, nanoCDRRead);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        int32_t length_in_aux = (uint32_t)std::strlen(string_seq_t[i]);
        int32_t length_out_aux = (uint32_t)std::strlen(string_out[i]);
        int32_t comparative_aux = std::strcmp(string_seq_t[i], string_out[i]);
        EXPECT_EQ(length_in_aux, length_out_aux);
        EXPECT_EQ(comparative_aux, 0);
        free(string_out[i]);
      }
      free(string_out);
  }

  TEST(nanoCDRSequencesEndiannessTests, CharSequence)
  {
      char * char_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeCharSequenceEndianness(char_seq_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeCharSequenceEndianness(&char_out, &size_out, endianness, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(char_seq_t[i], char_out[i]);
      }

      free(char_out);
  }

  TEST(nanoCDRSequencesEndiannessTests, UnsignedCharSequence)
  {
      unsigned char * char_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedCharSequenceEndianness(octet_seq_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedCharSequenceEndianness(&char_out, &size_out, endianness, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(octet_seq_t[i], char_out[i]);
      }

      free(char_out);
  }

  TEST(nanoCDRSequencesEndiannessTests, ShortSequence)
  {
      int16_t * short_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeShortSequenceEndianness(short_seq_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeShortSequenceEndianness(&short_out, &size_out, endianness, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(short_seq_t[i], short_out[i]);
      }

      free(short_out);
  }

  TEST(nanoCDRSequencesEndiannessTests, UnsignedShortSequence)
  {
      uint16_t * ushort_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedShortSequenceEndianness(ushort_seq_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedShortSequenceEndianness(&ushort_out, &size_out, endianness, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(ushort_seq_t[i], ushort_out[i]);
      }

      free(ushort_out);
  }

  TEST(nanoCDRSequencesEndiannessTests, IntSequence)
  {
      int32_t * int_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeIntSequenceEndianness(long_seq_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeIntSequenceEndianness(&int_out, &size_out, endianness, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(long_seq_t[i], int_out[i]);
      }

      free(int_out);
  }

  TEST(nanoCDRSequencesEndiannessTests, UnsignedIntSequence)
  {
      uint32_t * uint_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedIntSequenceEndianness(ulong_seq_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedIntSequenceEndianness(&uint_out, &size_out, endianness, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(ulong_seq_t[i], uint_out[i]);
      }

      free(uint_out);
  }

  TEST(nanoCDRSequencesEndiannessTests, LongSequence)
  {
      int64_t * long_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongSequenceEndianness(longlong_seq_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongSequenceEndianness(&long_out, &size_out, endianness, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(longlong_seq_t[i], long_out[i]);
      }

      free(long_out);
  }

  TEST(nanoCDRSequencesEndiannessTests, ULongSequence)
  {
      uint64_t * ulong_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedLongSequenceEndianness(ulonglong_seq_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedLongSequenceEndianness(&ulong_out, &size_out, endianness, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(ulonglong_seq_t[i], ulong_out[i]);
      }

      free(ulong_out);
  }

  TEST(nanoCDRSequencesEndiannessTests, LongLongSequence)
  {
      long long * longlong_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongLongSequenceEndianness(longlonglong_seq_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongLongSequenceEndianness(&longlong_out, &size_out, endianness, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(longlonglong_seq_t[i], longlong_out[i]);
      }

      free(longlong_out);
  }

  TEST(nanoCDRSequencesEndiannessTests, ULongLongSequence)
  {
      unsigned long long * ulonglong_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeUnsignedLongLongSequenceEndianness(ulonglonglong_seq_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeUnsignedLongLongSequenceEndianness(&ulonglong_out, &size_out, endianness, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(ulonglonglong_seq_t[i], ulonglong_out[i]);
      }

      free(ulonglong_out);
  }

  TEST(nanoCDRSequencesEndiannessTests, FloatSequence)
  {
      float * float_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeFloatSequenceEndianness(float_seq_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeFloatSequenceEndianness(&float_out, &size_out, endianness, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(float_seq_t[i], float_out[i]);
      }

      free(float_out);
  }

  TEST(nanoCDRSequencesEndiannessTests, DoubleSequence)
  {
      double * double_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeDoubleSequenceEndianness(double_seq_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeDoubleSequenceEndianness(&double_out, &size_out, endianness, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(double_seq_t[i], double_out[i]);
      }

      free(double_out);
  }

  TEST(nanoCDRSequencesEndiannessTests, LongDoubleSequence)
  {
      long double * longdouble_out;
      uint32_t size_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeLongDoubleSequenceEndianness(longdouble_seq_t, 5, endianness, nanoCDRWrite);

      // Deseriazliation.
      deserializeLongDoubleSequenceEndianness(&longdouble_out, &size_out, endianness, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        EXPECT_EQ(longdouble_seq_t[i], longdouble_out[i]);
      }

      free(longdouble_out);
  }

  TEST(nanoCDRSequencesEndiannessTests, StringSequence)
  {
      char ** string_out;
      char buffer[BUFFER_LENGTH];
      struct nanoBuffer * nanoBuffer = NULL;
      struct nanoCDR * nanoCDRWrite = NULL;
      struct nanoCDR * nanoCDRRead = NULL;

      // Check good case.
      newStaticBuffer(buffer, BUFFER_LENGTH, &nanoBuffer);
      newNanoCDR(&nanoCDRWrite, nanoBuffer);
      newNanoCDR(&nanoCDRRead, nanoBuffer);

      // Serialization.
      serializeStringSequenceEndianness(string_seq_t, 5, endianness, nanoCDRWrite);

      uint32_t size_out;

      // Deseriazliation.
      deserializeStringSequenceEndianness(&string_out, &size_out, endianness, nanoCDRRead);

      EXPECT_EQ(size_out, 5);

      int32_t i;
      for(i = 0; i < 5; i++)
      {
        int32_t length_in_aux = (uint32_t)std::strlen(string_seq_t[i]);
        int32_t length_out_aux = (uint32_t)std::strlen(string_out[i]);
        int32_t comparative_aux = std::strcmp(string_seq_t[i], string_out[i]);
        EXPECT_EQ(length_in_aux, length_out_aux);
        EXPECT_EQ(comparative_aux, 0);
        free(string_out[i]);
      }
      free(string_out);
  }
