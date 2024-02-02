#include "tests.h"

START_TEST(find_in_empty_str) {
  char s21_str[] = "";
  char s21_c = '\0';
  char str[] = "";
  char c = '\0';
  s21_size_t n = 0;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_empty_in_str) {
  char s21_str[] = "someIntellectualText";
  char s21_c = '\0';
  char str[] = "someIntellectualText";
  char c = '\0';
  s21_size_t n = 5;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_uppercase) {
  char s21_str[] = "hello";
  char s21_c = 'H';
  char str[] = "hello";
  char c = 'H';
  s21_size_t n = 5;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_in_start) {
  char s21_str[] = "Hello";
  char s21_c = 'H';
  char str[] = "Hello";
  char c = 'H';
  s21_size_t n = 5;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_in_end) {
  char s21_str[] = "hello";
  char s21_c = 'o';
  char str[] = "hello";
  char c = 'o';
  s21_size_t n = 5;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_num_in_string) {
  char s21_str[] = "hel3523522lo";
  char s21_c = '2';
  char str[] = "hel3523522lo";
  char c = '2';
  s21_size_t n = 10;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_num_in_array) {
  int s21_arr[] = {1, 43, 235, 7, 23, 111, 9, 0};
  int s21_c = 235;
  int arr[] = {1, 43, 235, 7, 23, 111, 9, 0};
  int c = 235;
  s21_size_t n = sizeof(int) * 8;

  ck_assert_pstr_eq(s21_memchr(s21_arr, s21_c, n), memchr(arr, c, n));
}
END_TEST

Suite* suite_memchr() {
  Suite* suite = suite_create("memchr_suite");
  TCase* tcase_core = tcase_create("memchr_tc");

  tcase_add_test(tcase_core, find_in_empty_str);
  tcase_add_test(tcase_core, find_empty_in_str);
  tcase_add_test(tcase_core, find_uppercase);
  tcase_add_test(tcase_core, find_in_start);
  tcase_add_test(tcase_core, find_in_end);
  tcase_add_test(tcase_core, find_num_in_string);
  tcase_add_test(tcase_core, find_num_in_array);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(str1_more_str2) {
  const char str1[] = "1a3bc";
  const char str2[] = "123abc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(str1_less_str2) {
  const char str1[] = "123abc";
  const char str2[] = "1a3bc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(equal) {
  const char str1[] = "123abc";
  const char str2[] = "123abc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

Suite* suite_memcmp() {
  Suite* suite = suite_create("memcmp_suite");
  TCase* tcase_core = tcase_create("memcmp_tc");

  tcase_add_test(tcase_core, str1_more_str2);
  tcase_add_test(tcase_core, str1_less_str2);
  tcase_add_test(tcase_core, equal);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(simple_copy) {
  char s21_dest[5] = "";
  const char s21_src[] = "12345";
  const char src[] = "12345";
  char dest[5] = "";
  s21_size_t n = 3;

  ck_assert_str_eq(s21_memcpy((void *)s21_dest, s21_src, n),
                   memcpy((void *)dest, src, n));
}
END_TEST

START_TEST(n_zero) {
  char s21_dest[5] = "";
  const char s21_src[] = "12345";
  const char src[] = "12345";
  char dest[5] = "";
  s21_size_t n = 0;

  ck_assert_str_eq(s21_memcpy((void *)s21_dest, s21_src, n),
                   memcpy((void *)dest, src, n));
}
END_TEST

START_TEST(rewrite_test) {
  char s21_dest[25] = "Hello";
  const char s21_src[] = "zzzzz_world";
  const char src[] = "zzzzz_world";
  char dest[25] = "Hello";
  s21_size_t n = 6;

  ck_assert_str_eq(s21_memcpy((void *)s21_dest, s21_src, n),
                   memcpy((void *)dest, src, n));
}
END_TEST

START_TEST(test_with_underline) {
  char s21_dest[25] = "";
  const char s21_src[] = "Hello_world";
  const char src[] = "Hello_world";
  char dest[25] = "";
  s21_size_t n = 12;

  ck_assert_str_eq(s21_memcpy((void *)s21_dest, s21_src, n),
                   memcpy((void *)dest, src, n));
}
END_TEST

Suite *suite_memcpy() {
  Suite *suite = suite_create("memcpy_suite");
  TCase *tcase_core = tcase_create("memcpy_tc");

  tcase_add_test(tcase_core, simple_copy);
  tcase_add_test(tcase_core, n_zero);
  tcase_add_test(tcase_core, rewrite_test);
  tcase_add_test(tcase_core, test_with_underline);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(some_test) {
  char s21_dest[] = "someIntellectualText";
  char s21_src = 'i';
  char dest[] = "someIntellectualText";
  char src = 'i';
  s21_size_t n = 7;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

START_TEST(zero_n_test) {
  char s21_dest[] = "someIntellectualText";
  char s21_src = 'i';
  char dest[] = "someIntellectualText";
  char src = 'i';
  s21_size_t n = 0;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

START_TEST(empty_test) {
  char s21_dest[] = "";
  char s21_src = '\0';
  char dest[] = "";
  char src = '\0';
  s21_size_t n = 0;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

START_TEST(replace_number_test) {
  char s21_dest[] = "hello";
  char s21_src = '2';
  char dest[] = "hello";
  char src = '2';
  s21_size_t n = 3;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

START_TEST(replace_register_test) {
  char s21_dest[] = "hello";
  char s21_src = 'H';
  char dest[] = "hello";
  char src = 'H';
  s21_size_t n = 1;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

START_TEST(long_test) {
  char s21_dest[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce nec "
      "tempus felis. Nullam dapibus nam.";
  char s21_src = '*';
  char dest[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce nec "
      "tempus felis. Nullam dapibus nam.";
  char src = '*';
  s21_size_t n = 10;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

Suite* suite_memset() {
  Suite* suite = suite_create("memset_suite");
  TCase* tcase_core = tcase_create("memset_tc");

  tcase_add_test(tcase_core, some_test);
  tcase_add_test(tcase_core, zero_n_test);
  tcase_add_test(tcase_core, empty_test);
  tcase_add_test(tcase_core, replace_number_test);
  tcase_add_test(tcase_core, replace_register_test);
  tcase_add_test(tcase_core, long_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(empty_str) {
  char str[] = "";
  int c = '1';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(some_cin_str) {
  char str[] = "hellell56o";
  int c = '5';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(empty_str_and_c) {
  char str[] = "";
  int c = '\0';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(empty_c) {
  char str[] = "Some meaningless text";
  int c = '\0';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(regular_test) {
  char str[] = "1Greetings";
  int c = '1';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(no_match_test) {
  char str[] = "i need this text";
  int c = '5';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(one_symbol_test) {
  char str[] = "1";
  int c = '1';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

Suite* suite_strchr() {
  Suite* suite = suite_create("strchr_suite");
  TCase* tcase_core = tcase_create("strchr_tc");
  tcase_add_test(tcase_core, empty_str);
  tcase_add_test(tcase_core, some_cin_str);
  tcase_add_test(tcase_core, empty_c);
  tcase_add_test(tcase_core, empty_str_and_c);
  tcase_add_test(tcase_core, regular_test);
  tcase_add_test(tcase_core, no_match_test);
  tcase_add_test(tcase_core, one_symbol_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(len1) {
  char str[] = "hellell56o";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(len2) {
  char str[] = "";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(len3) {
  char str[] = "1";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite* suite_strlen() {
  Suite* suite = suite_create("strlen_suite");
  TCase* tcase_core = tcase_create("strlen_tc");
  tcase_add_test(tcase_core, len1);
  tcase_add_test(tcase_core, len2);
  tcase_add_test(tcase_core, len3);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(empty_s1) {
  char s1[] = "";
  char s2[] = "Hello everyone123";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(some_s1_in_s2) {
  char s1[] = "hellello";
  char s2[] = "el";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(empty_s1s2) {
  char s1[] = "";
  char s2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(empty_s2) {
  char s1[] = "Some meaningless text";
  char s2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(reg_test) {
  char s1[] = "Hello World";
  char s2[] = "World";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(no_m_test) {
  char s1[] = "i need this text";
  char s2[] = "sorry";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(register_test) {
  char s1[] = "Hello World";
  char s2[] = "world";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(one_sym_test) {
  char s1[] = "Hi";
  char s2[] = "i";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

Suite* suite_strncat() {
  Suite* suite = suite_create("strncat_suite");
  TCase* tcase_core = tcase_create("strncat_tc");

  tcase_add_test(tcase_core, empty_s1);
  tcase_add_test(tcase_core, some_s1_in_s2);
  tcase_add_test(tcase_core, empty_s1s2);
  tcase_add_test(tcase_core, empty_s2);
  tcase_add_test(tcase_core, reg_test);
  tcase_add_test(tcase_core, no_m_test);
  tcase_add_test(tcase_core, register_test);
  tcase_add_test(tcase_core, one_sym_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(empty) {
  const char str1[] = "";
  const char str2[] = "";
  s21_size_t n = 1;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(empty_str1) {
  const char str1[] = "";
  const char str2[] = "123";
  s21_size_t n = 1;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(empty_str2) {
  const char str1[] = "123";
  const char str2[] = "";
  s21_size_t n = 1;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(str1_m_str2) {
  const char str1[] = "1a3bc";
  const char str2[] = "123abc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(str1_l_str2) {
  const char str1[] = "123abc";
  const char str2[] = "1a3bc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

Suite* suite_strncmp() {
  Suite* suite = suite_create("strncmp_suite");
  TCase* tcase_core = tcase_create("strncmp_tc");

  tcase_add_test(tcase_core, empty);
  tcase_add_test(tcase_core, empty_str1);
  tcase_add_test(tcase_core, empty_str2);
  tcase_add_test(tcase_core, str1_m_str2);
  tcase_add_test(tcase_core, str1_l_str2);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(emp) {
  char s21_dest[] = "";
  char s21_src[] = "";
  char dest[] = "";
  char src[] = "";
  s21_size_t n = 0;

  ck_assert_str_eq(s21_strncpy(s21_dest, s21_src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(n_ze) {
  char s21_dest[] = "Hello";
  char s21_src[] = "world";
  char dest[] = "Hello";
  char src[] = "world";
  s21_size_t n = 0;

  ck_assert_str_eq(s21_strncpy(s21_dest, s21_src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(empty_dest) {
  char s21_dest[3] = "";
  char s21_src[20] = "Lorem ipsum integer";
  char dest[3] = "";
  char src[20] = "Lorem ipsum integer";
  s21_size_t n = 2;

  ck_assert_str_eq(s21_strncpy(s21_dest, s21_src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(not_enough_byte_n) {
  char s21_dest[30] = "Lorem ipsum";
  char s21_src[20] = "Lorem ipsum integer";
  char dest[30] = "Lorem ipsum";
  char src[20] = "Lorem ipsum integer";
  s21_size_t n = 1;

  ck_assert_str_eq(s21_strncpy(s21_dest, s21_src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(enough_byte_n) {
  char s21_dest[30] = "Lorem ipsum";
  char s21_src[20] = "Lorem ipsum integer";
  char dest[30] = "Lorem ipsum";
  char src[20] = "Lorem ipsum integer";
  s21_size_t n = 19;

  ck_assert_str_eq(s21_strncpy(s21_dest, s21_src, n), strncpy(dest, src, n));
}
END_TEST

Suite* suite_strncpy() {
  Suite* suite = suite_create("strncpy_suite");
  TCase* tcase_core = tcase_create("strncpy_tc");

  tcase_add_test(tcase_core, emp);
  tcase_add_test(tcase_core, n_ze);
  tcase_add_test(tcase_core, empty_dest);
  tcase_add_test(tcase_core, not_enough_byte_n);
  tcase_add_test(tcase_core, enough_byte_n);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(emp_s1) {
  char s1[] = "";
  char s2[] = "Hello everyone123";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(so_s1_in_s2) {
  char s1[] = "hellello";
  char s2[] = "el";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(emp_s1s2) {
  char s1[] = "";
  char s2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(emp_s2) {
  char s1[] = "Some meaningless text";
  char s2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(regul_test) {
  char s1[] = "Hello World";
  char s2[] = "World";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(no_matc_test) {
  char s1[] = "i need this text";
  char s2[] = "sorry";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(regis_test) {
  char s1[] = "Hello World";
  char s2[] = "world";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(one_symbo_test) {
  char s1[] = "Hi";
  char s2[] = "i";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

Suite* suite_strpbrk() {
  Suite* suite = suite_create("strpbrk_suite");
  TCase* tcase_core = tcase_create("strpbrk_tc");

  tcase_add_test(tcase_core, emp_s1);
  tcase_add_test(tcase_core, so_s1_in_s2);
  tcase_add_test(tcase_core, emp_s1s2);
  tcase_add_test(tcase_core, emp_s2);
  tcase_add_test(tcase_core, regul_test);
  tcase_add_test(tcase_core, no_matc_test);
  tcase_add_test(tcase_core, regis_test);
  tcase_add_test(tcase_core, one_symbo_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(empty_st) {
  char str[] = "";
  int c = '1';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(some_cin_st) {
  char str[] = "hellell556o";
  int c = '5';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(empty_st_and_c) {
  char str[] = "";
  int c = '\0';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(empt_c) {
  char str[] = "Some meaningless text";
  int c = '\0';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(regula_test) {
  char str[] = "1Greetings";
  int c = '1';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(no_match_tes) {
  char str[] = "i need this text";
  int c = '5';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(one_symbol_tes) {
  char str[] = "1";
  int c = '1';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

Suite* suite_strrchr() {
  Suite* suite = suite_create("strrchr_suite");
  TCase* tcase_core = tcase_create("strrchr_tc");
  tcase_add_test(tcase_core, empty_st);
  tcase_add_test(tcase_core, some_cin_st);
  tcase_add_test(tcase_core, empt_c);
  tcase_add_test(tcase_core, empty_st_and_c);
  tcase_add_test(tcase_core, regula_test);
  tcase_add_test(tcase_core, no_match_tes);
  tcase_add_test(tcase_core, one_symbol_tes);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(empty_haystack) {
  char haystack[] = "";
  char needle[] = "Hello everyone123";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(some_needle_in_haystack) {
  char haystack[] = "hellello";
  char needle[] = "el";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(empty_haystack_and_needle) {
  char haystack[] = "";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(empty_needle) {
  char haystack[] = "Some meaningless text";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(egular_test) {
  char haystack[] = "Hello World";
  char needle[] = "World";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(o_match_test) {
  char haystack[] = "i need this text";
  char needle[] = "sorry";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(egister_test) {
  char haystack[] = "Hello World";
  char needle[] = "world";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(ne_symbol_test) {
  char haystack[] = "Hi";
  char needle[] = "i";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

Suite* suite_strstr() {
  Suite* suite = suite_create("strstr_suite");
  TCase* tcase_core = tcase_create("strstr_tc");

  tcase_add_test(tcase_core, empty_haystack);
  tcase_add_test(tcase_core, some_needle_in_haystack);
  tcase_add_test(tcase_core, empty_haystack_and_needle);
  tcase_add_test(tcase_core, empty_needle);
  tcase_add_test(tcase_core, egular_test);
  tcase_add_test(tcase_core, o_match_test);
  tcase_add_test(tcase_core, egister_test);
  tcase_add_test(tcase_core, ne_symbol_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(simple_token_string) {
  char s21_str[] = "Maecenas++mollis_*_!malesuada massa=======vitae";
  char str[] = "Maecenas++mollis__!malesuada massa=======vitae";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(hard_token_string) {
  char s21_str[] = "      Maecenas++mollis__! D !malesuada _massa=======vitae ";
  char str[] = "      Maecenas++mollis__! D !malesuada _massa=======vitae ";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(not_all_delims) {
  char s21_str[] = "Maecenas++mollis__!D!malesuada_massa=======vitae";
  char str[] = "Maecenas++mollis__!D!malesuada_massa=======vitae*";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(no_delims) {
  char s21_str[] = "MaecenasmollisMalesuadaMassaVitae";
  char str[] = "MaecenasmollisMalesuadaMassaVitae";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(delims_str) {
  char s21_str[] = "++!!= _";
  char str[] = "++!!= _";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_pstr_eq(s21, system);
}
END_TEST

START_TEST(delims_in_word) {
  char s21_str[] = "Maece+*+nasmollis    !malesu     ada=massa___vitae";
  char str[] = "Maece++nasmollis    !malesu     ada=massa___vitae";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(hard_word) {
  char s21_str[] = "!M+*+N***L M=M_F_V*H";
  char str[] = "!M+*+N***L M=M_F_V*H";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(hard_string) {
  char s21_str[] =
      "        !          Maece+*+nasmol***lis    !malesu     "
      "ada=massa_f__vitae*** *** *** hi";
  char str[] =
      "        !          Maece+*+nasmol***lis    !malesu     "
      "ada=massa_f__vitae*** *** *** hi";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

Suite *suite_strtok() {
  Suite *suite = suite_create("strtok_suite");
  TCase *tcase_core = tcase_create("strtok_tc");

  tcase_add_test(tcase_core, simple_token_string);
  tcase_add_test(tcase_core, hard_token_string);
  tcase_add_test(tcase_core, not_all_delims);
  tcase_add_test(tcase_core, no_delims);
  tcase_add_test(tcase_core, delims_str);
  tcase_add_test(tcase_core, delims_in_word);
  tcase_add_test(tcase_core, hard_word);
  tcase_add_test(tcase_core, hard_string);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(e) {
    char src[] = "";
    char res[] = "";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(gora_) {
    char src[] = "gora";
    char res[] = "";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(_gora) {
    char src[] = "";
    char res[] = "gora";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(any_register) {
    char src[] = "gora";
    char res[] = "gOra";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(num_num) {
    char src[] = "123";
    char res[] = "123";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(long_num_num) {
    char src[] = "12345";
    char res[] = "123";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(num_long_num) {
    char src[] = "123";
    char res[] = "12345";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(any_num) {
    char src[] = "1234567890";
    char res[] = "0987654321";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(num_with_letter) {
    char src[] = "1A2A3A4A5A";
    char res[] = "123";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(num_with_letter2) {
    char src[] = "a1aaa23aaa41235";
    char res[] = "123";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(basic_test) {
    char src[] = "absD";
    char res[] = "aD";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(any_sim) {
    char src[] = "32ASDASDPare[0g9jf m07y271234567890";
    char res[] = "0987654321";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(upper_letter) {
    char src[] = "32ASDASDPare[0g9jf m07y271234567890";
    char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(lower_letter) {
    char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
    char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(not_uniq_sim) {
    char src[] = "33333";
    char res[] = "11133";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

Suite *suite_strcspn(void) {
    Suite *s = suite_create("suite_strcspn");
    TCase *tc = tcase_create("strcspn_tc");

    tcase_add_test(tc, e);
    tcase_add_test(tc, gora_);
    tcase_add_test(tc, _gora);
    tcase_add_test(tc, any_register);
    tcase_add_test(tc, num_num);
    tcase_add_test(tc, long_num_num);
    tcase_add_test(tc, num_long_num);
    tcase_add_test(tc, any_num);
    tcase_add_test(tc, num_with_letter);
    tcase_add_test(tc, num_with_letter2);
    tcase_add_test(tc, basic_test);
    tcase_add_test(tc, any_sim);
    tcase_add_test(tc, upper_letter);
    tcase_add_test(tc, lower_letter);
    tcase_add_test(tc, not_uniq_sim);

    suite_add_tcase(s, tc);
    return s;
}