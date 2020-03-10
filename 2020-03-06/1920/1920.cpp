#include <cstdio>

int arr[100003], arr2[100003];

void mergeSort(int start, int end);
void merge(int start, int mid, int end);

int main(){
	int N, M;
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d", arr[i]);

	scanf("%d", &N);

	for(int i = 0; i < M; i++)
		scanf("%d", &arr2[i]);


}

void mergeSort(int start, int end){
	if(start < end){
		int mid = (start + end)/2;
		mergeSort(start, mid);
		mergeSort(mid+1, end);
	}
}
void merge(int start, int mid, int end){

}
const useInput = (initialValue, validator) => {
  const [value, changeValue] = useState(initialValue);
  const onChange = event => {
    const {
      target: { value }
    } = event;

    if (typeof validator === "function" && validator(value)) {
      changeValue(value);
    }
  };
  return { value, onChange };
};