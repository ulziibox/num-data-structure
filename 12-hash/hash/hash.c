#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N  1000000

struct Student {
	char ovog[20];
	char ner[20];
	char id[11];
};
struct Elm {
	struct Student x;
	struct Elm *next;
};

struct Elm *head[N], *tail[N];

void push_back(int h, struct Student x);
void insert(const struct Student x);
int hash(const char s[]);
void init_hash_table();
struct Student *search(const char id[]);
void del(const char id[]);
void update(const struct Student x);

void push_back(int h, struct Student x)
{
	struct Elm *_head = head[h];
	struct Elm *_tail = tail[h];
	/*
	  Жагсаалтан хүснэгтэд h хайш индекс дээр оруулна
	 */

	head[h] = _head;
	tail[h] = _tail;
}

void insert(const struct Student x)
{
	int h = hash(x.id);
	push_back(h, x);
}

int hash(const char s[])
{
	/*
	  s - тэмдэгтэн цувааны хайшыг тооцоолоод буцаах функцыг
	  хэрэгжүүлнэ үү.
	 */
	return 0;
}

void init_hash_table()
{
	int i;
	for (i = 0; i < N; i++)
		head[i] = tail[i] = NULL;
}

struct Student *search(const char id[])
{
	/*
	  Өгөгдсөн id-аар оюутны мэдээллийг хайх функц.
	  Олдохгүй бол NULL утга буцаана.
	 */
}

void update(const struct Student x)
{
	/*
	  x-д байгаа оюутны id-тай адил оюутан байвал түүний мэдээллийг солиж хадгална.
	  Байхгүй бол шинээр оруулна.
	 */
}

void del(const char id[])
{
	/*
	  id-тай оюутан олдвол түүнийг устгана.
	  Олдохгүй бол юу ч хийхгүй.
	 */
}



void print(FILE *fout, struct Student *p)
{
	if (p == NULL) {
		fprintf(fout, "xooson\n");
		return;
	}
	fprintf(fout, "%s %s %s\n", p->ovog, p->ner, p->id);
}

void release_hashtable()
{
	/* Хайш хүснэгтийн бүх элементүүдийг устгах функц */
}

int main()
{
	int n, i, j, m;
	FILE *fin;
	fin = fopen("student.info", "r");
	if (fin == NULL) {
		printf("student.info file oldsongui\n");
		exit(1);
	}
	fscanf(fin, "%d", &n);
	struct Student x, *p;
	for (i = 0; i < n; i++) {
		fscanf(fin, "%s%s%s", x.ovog, x.ner, x.id);
		insert(x);
	}
	fclose(fin);
	fin = fopen("input.txt", "r");
	char cmd[10];
	fscanf(fin, "%d", &m);
	FILE *fout = fopen("myoutput.txt", "w");

	for (i = 0; i < m; i++) {
		fscanf(fin, "%s", cmd);
		if (strcmp(cmd, "search") == 0) {
			fscanf(fin, "%s", x.id);
			p = search(x.id);
			print(fout, p);
		} else if (strcmp(cmd, "update") == 0) {
			fscanf(fin, "%s%s%s", x.ovog, x.ner, x.id);
			update(x);
		} else if (strcmp(cmd, "delete") == 0) {
			fscanf(fin, "%s", x.id);
			del(x.id);
		}
	}
	fclose(fin);
	fclose(fout);
	release_hashtable();
	return 0;
}
