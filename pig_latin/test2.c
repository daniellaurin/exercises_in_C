
#include <assert.h>

#include <ctype.h>

#include <stdbool.h>

#include <stdlib.h>

#include <string.h>

#define NEW_SUFFIX "ay"

#define NEW_SUFFIX_LEN (sizeof(NEW_SUFFIX) - 1)

struct string

{

  const char *ptr;

  size_t len;
};

static size_t count_words(const char *phrase)

{

  bool previous_is_alpha = false;

  size_t count = 0;

  for (; *phrase; ++phrase)

  {

    bool current_is_alpha = isalpha((unsigned char)*phrase);

    count += (previous_is_alpha != current_is_alpha);

    previous_is_alpha = current_is_alpha;
  }

  return count;
}

static struct string find_next_word(const char *phrase)

{

  for (; *phrase; ++phrase)

    if (isalpha((unsigned char)*phrase))

      break;

  struct string word = {.ptr = phrase};

  for (; *phrase; ++phrase)

  {

    if (!isalpha((unsigned char)*phrase))

      break;

    ++word.len;
  }

  return word;
}

static size_t append(char *dst, const char *src, size_t n)

{

  memcpy(dst, src, n);

  return n;
}

static bool is_vowel(char c)

{

  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

static struct string find_prefix(struct string word)

{

  struct string prefix = {.ptr = word.ptr};

  // two special cases:

  // "xr" at the beginning of word is pronounced "exr", treated as a vowel

  if (strncmp(word.ptr, "xr", 2) == 0)

    return prefix;

  // "y" followed by a vowel is treated like a consonant

  if (word.len >= 2 && word.ptr[0] == 'y' && is_vowel(word.ptr[1]))

  {

    prefix.len = 1;

    return prefix;
  }

  for (; prefix.len < word.len; ++prefix.len)

  {

    if (is_vowel(prefix.ptr[prefix.len]))

      break;

    if (prefix.ptr[prefix.len] == 'q' &&

        prefix.len + 1 < word.len &&

        prefix.ptr[prefix.len + 1] == 'u')

      ++prefix.len;
  }

  return prefix;
}

char *translate(const char *phrase)

{

  assert(phrase);

  size_t phrase_len = strlen(phrase);

  size_t word_count = count_words(phrase);

  char *result = malloc(phrase_len + word_count * NEW_SUFFIX_LEN + 1),
       *result_end = result;

  if (!result)

    return NULL;

  for (;;)

  {

    struct string word = find_next_word(phrase);

    struct string separator = {.ptr = phrase, .len = word.ptr - phrase};

    result_end += append(result_end, separator.ptr, separator.len);

    if (word.len == 0)

      break;

    struct string prefix = find_prefix(word);

    struct string suffix = {.ptr = word.ptr + prefix.len,
                            .len = word.len - prefix.len};

    result_end += append(result_end, suffix.ptr, suffix.len);

    result_end += append(result_end, prefix.ptr, prefix.len);

    result_end += append(result_end, NEW_SUFFIX, NEW_SUFFIX_LEN);

    phrase = word.ptr + word.len;
  }

  *result_end = '\0';

  return result;
}