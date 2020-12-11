#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Tree
{
	int len;  // Нийт багтаамж
	int size; // Одоогийн хэмжээ
	int *dat; // Өгөгдөл хадгалах хүснэгтийг заах хаяг
};

int error = 0;
const char error_msg[][50] = {
	"",
	"Mod duuren!",
	"Mod hooson!",
};

void init(struct Tree *p, int n)
{
	p->len = n;
	p->size = 0;
	p->dat = (int *)malloc(sizeof(int) * n);
}

void release(struct Tree *p)
{
	free(p->dat);
	p->dat = NULL;
}

/* p-ийн зааж буй Tree-с x тоог хайн олдсон байрлалыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
int find(struct Tree *p, int x)
{
	//Эхнээс нь орой бүрээр шалгаж хайна
	for (int i = 0; i < p->size; i++)
		//*(p->dat) хаяган хувьсагчийн хадгалж буй утгыг
		//dat нь хүснэгтийн эхлэл тул i index-г шууд нэмж өгч байгаа
		if (x == *(p->dat + i))
			return i;
}

/* p-ийн зааж буй модноос idx-ээр root хийсэн дэд модны  Tree-ийн өндрийг буцаана */
int height(struct Tree *p, int idx)
{
	/* Энд өндрийг олох үйлдлийг хийнэ */

	//ТОДОРХОЙЛОЛТ: Өндөр гэдэг нь үндээс навч хүртэлх түвшинг хэлж буй юм.
	int height = 0;
	while (idx < p->size)
	{
		//Тухайн орой бүрийн зүүн хүүг олж height -г нэгээр нэмэгдүүлнэ
		idx = 2 * idx + 1;
		height++;
	}
	printf("Height: %d\n", height);
	// return height;
}

/* p-ийн зааж буй Tree-д x утгыг оруулна */
void add(struct Tree *p, int x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
	//Энгийн хүснэгттэй адил сүүлээсээ элемент нэмж байгаа учир
	//size нь харин хамгийн сүүлийн index -г зааж өгөх чадвартай
	p->dat[p->size] = x;
	p->size++;
}

/* p-ийн зааж буй Tree-с idx дугаартай зангилаанаас доошхи бүх навчийг олно */
void leaves(struct Tree *p, int idx)
{
	/* Энд навчуудыг үйлдлийг хийнэ үү */

	//ТОДОРХОЙЛОЛТ: Навч буюу Leafs нь хүүхэдгүй оройг хэлдэг
	int n, i = idx;
	//Төгсгөл хүртэл гүйнэ
	while (i < p->size)
	{
		i = 2 * i + 1;	 //Зүүн хүү
		idx = 2 * i + 2; //Баруун хүү
	}

	i = (i - 1) / 2;	 //Зүүн хүүгийн эцгийг олох
	idx = (idx - 2) / 2; //Баруун хүүгийн эцгийг олох

	//Навчны эхэнд ирэх
	if (idx < p->size)
		n = idx;
	else
		n = p->size;

	//Навчуудыг хэвлэх
	while (i <= n)
	{
		printf(" %d,", *(p->dat + i));
		i++;
	}
}

/* p-ийн зааж буй Tree-г idx дугаартай зангилаанаас эхлэн preorder-оор хэвлэ */
void preorder(struct Tree *p, int idx)
{
	/* Энд pre-order-оор хэвлэх үйлдлийг хийнэ үү */
	if (idx < p->size)
	{
		//ТОДОРХОЙЛОЛТ: 3 төрлийн traversal байдаг бөгөөд үүний нэг нь preorder.
		//preorder нь модоор гүйж элементийг хэвлэхдээ
		//root - left - right гэсэн дүрмээр явдаг.
		printf("%d\n", p->dat[idx]);
		preorder(p, 2 * idx + 1);
		preorder(p, 2 + idx + 2);
	}
}

/* p-ийн зааж буй Tree-д idx зангилаанаас доошхи бүх үр садыг хэвлэнэ  */
void descendants(struct Tree *p, int idx)
{
	/* Энд үр садыг олох үйлдлийг хийнэ үү */
	//Зүүн хүүхдэд preorder traversal-г хийхэд хангалттай
	preorder(p, 2 * idx + 1);
}

/* p-ийн зааж буй Tree-д idx зангилаанаас дээшхи бүх өвөг эцэгийг олох үйлдлийг хийнэ */
void ancestors(struct Tree *p, int idx)
{
	/* Энд өвөг эцгийг олох үйлдлийг хийнэ үү */
	//Үндэс хүртэл давталт гүйлгэнэ
	while (idx > 0)
	{
		//Хэрвээ тухайн орой эцэгтэй байвал хэвлэх үйлдэл хийнэ.
		if ((idx - 1) / 2 >= 0)
			printf(" %d,", p->dat[(idx - 1) / 2]);

		//Давталтын index бөгөөд idx-д эцгийн индексийн оноож өгөх буюу
		//нэг түвшин дээшлүүлж байгаа. Ингэснээр үндэс хүртэл дээшээ
		//явах боломжтой
		idx = (idx - 1) / 2;
	}
	printf("\n");
}

/* p-ийн зааж буй Tree-д idx дугаартай зангилааны ах, дүүгийн зангилааны дугаарыг буцаана
   (Нэг эцэгтэй зангилаа). Байхгүй бол -1-г буцаана
 */
int sibling(struct Tree *p, int idx)
{
	/* Энд ах, дүүг олох үйлдлийг хийнэ үү */

	//ТОДОРХОЙЛОЛТ: Ах дүү гэдэг нь ижил эцэгтэй оройнуудыг хэлдэг
	//Binary Tree зөвхөн нэг л ах дүүтэй байна.
	if (idx > 0)
	{
		//Баруун эсвэл зүүн аль хүүг нь оруулж ирснийг мэдэхгүй учир
		//эхлээд тухайн оройн эцгийг олно
		int parent_idx = (idx - 1) / 2;

		//Үүний дараа зүүн хүүтэй нь тулгаж үзээд, хэрэв таарч байвал
		//ах дүү болох баруун хүүгийн index-г буцаана
		if (2 * parent_idx + 1 == idx)
			return 2 * parent_idx + 2;
		else
			//Эсрэг тохиодолд баруун хүү орж ирсэн гэж үзэн, зүүн
			//хүүгийн index-г буцаана
			return 2 * parent_idx + 1;
	}
	else
		return -1;

	// if (idx + 1 < p->size)
	// 	return idx + 1;
	// return -1;
}

/* p-ийн зааж буй Tree-д idx дугаартай зангилааны хүүхдүүдийн утгыг хэвлэ.
 */
void children(struct Tree *p, int idx)
{
	/* Энд хүүхдүүдийн утгыг хэвлэх үйлдлийг хийнэ үү */

	//Зүүн хүүхдийн индексийн тоо одоо байгаа модны хэмжээнээс
	//их байвал хүүхэдгүй гэсэн үг учир шалгаж байна
	if (2 * idx + 1 < p->size)
	{
		//Зүүн хүүхэд байгаа учир хэвлээд баруун хүүхэд рүү
		//адил утгаар хандана
		printf(" %d \n", p->dat[2 * idx + 1]);
		if (2 * idx + 2 < p->size)
			printf(" %d\n", p->dat[2 * idx + 2]);
		else
			//Баруун хүүхэд байхгүй үед хэвлэгдэнэ
			printf("Huuhedgui \n");
	}
	else
		printf("Huuhedgui \n");
}
/* p-ийн зааж буй Tree-д idx дугаартай зангилааны эцгийн утгыг хэвлэ.
 */
void parent(struct Tree *p, int idx)
{
	//Эцгийг олохдоо зүүн, баруун хүү гэдгээс үл хамааран
	// (idx - 1) / 2 гэсэн алгоритмаар олно. Хуваахдаа бүхлийг нь
	//авч байгааг анзаараарай
	if ((idx - 1) / 2 > 0)
		printf("Etseg: %d\n", p->dat[(idx - 1) / 2]);
	else
		//Бүтэн модны үндэс нь өөрөө эцэггүй
		printf("Etseggui\n");
}

/* p-ийн зааж буй Tree-г idx дугаартай зангилаанаас эхлэн in-order-оор хэвлэ */
void inorder(struct Tree *p, int idx)
{
	/* Энд in-order-оор хэвлэх үйлдлийг хийнэ үү */
	if (idx < p->size)
	{
		//ТОДОРХОЙЛОЛТ: inorder traversal дээр left - root - right гэсэн
		//дүрмээр явна
		inorder(p, 2 * idx + 1); //left
		printf("%d\n", p->dat[idx]);
		inorder(p, 2 + idx + 2); //right
	}
}

/* p-ийн зааж буй Tree-г idx дугаартай зангилаанаас эхлэн post-order-оор хэвлэ */
void postorder(struct Tree *p, int idx)
{
	/* Энд post-order-оор хэвлэх үйлдлийг хийнэ үү */
	if (idx < p->size)
	{
		//ТОДОРХОЙЛОЛТ: postorder traversal дээр left - right - root гэсэн
		//дүрмээр явна
		postorder(p, 2 * idx + 1); //left
		postorder(p, 2 + idx + 2); //right
		printf("%d\n", p->dat[idx]);
	}
}

/* p-ийн зааж буй Tree-д idx дугаартай зангилаанаас үндэс хүртэлх оройнуудын тоог буцаана.
   x тоо олдохгүй бол -1-г буцаана.
 */
int level(struct Tree *p, int idx)
{
	//ТОДОРХОЙЛОЛТ: Түвшин буюу level нь тухайн оройноос үндэс хүртэлх оройн
	//тоон дээр нэгийг нэмэхэд тодорхойлогдоно. Тийм учир
	//тэгээс биш нэгээс level-г эхлүүлнэ
	int level = 1;

	//Эцэггүй орой хүртэл дээшээ гүйнэ. Ингэхдээ level -г
	//нэгээр нэмэгдүүлж олно.
	while (idx > 0)
	{
		idx = (idx - 1) / 2;
		level++;
	}

	printf("Level is: %d\n", level);
}
#endif
