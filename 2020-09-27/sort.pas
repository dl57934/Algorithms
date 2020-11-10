program sort;

var quickSortInput, mergeSortInput:array[1..10] of integer;
    i:integer;
   
function swap(var c1,c2:integer) : integer;
 var temp:integer;
 begin
   temp:=c1;
   c1:=c2;
   c2:=temp;
 end;
    
function quickSort(s, e: integer) : integer;
var pivot, l, r: integer;
begin
  pivot := quickSortInput[(s + e) div 2];
  l := s;
  r := e;
  while l < r do
  begin
    while quickSortInput[l] < pivot do l:=l+1;
    while quickSortInput[r] > pivot do r:=r-1;

    if l <= r then 
      swap(quickSortInput[l], quickSortInput[r]);
      l:=l+1;
      r:=r-1;
  end;

  if s < l - 1 then 
  quickSort(s, l-1);
  if l < e then 
  quickSort(l, e);
end;

function merge(s, mid, e: integer) : integer;
var part1, part2, index : integer; 
var temp:array[1..10] of integer;
begin
  part1 := s;
  part2 := mid+1;
  index := s;
  for i := s to e do begin
   temp[i] := mergeSortInput[i]                   
  end;

  while ((part1 <= mid) and (part2 <= e)) do
  begin
    if temp[part1] < temp[part2] then
    begin
      mergeSortInput[index] := temp[part1];
      part1 := part1 + 1;
    end
    else
    begin
      mergeSortInput[index] := temp[part2];
      part2 := part2 + 1;
    end;
    index := index + 1;
  end;
  for i := 0 to (mid - part1) do 
   mergeSortInput[i + index] := temp[i + part1];
end;

function mergeSort(s, e: integer) : integer;
var mid : integer; 
begin
  if s < e then 
  begin
    mid := (s + e) div 2;
    mergeSort(s, mid);
    mergeSort(mid + 1, e);
    merge(s, mid, e);
  end;
end;


begin
  writeln('quicksort(nlogn ~ n^2)');
  writeln('before');
   for i := 1 to 10 do begin
                      readln(quickSortInput[i]);
                  end;

   quickSort(1, 10);
 
   writeln('after');
   for i := 1 to 10 do begin
                      write(quickSortInput[i]);
                      write(' ');
                  end;
  writeln();
  writeln();
  writeln('mergeSort(nlogn)');
  writeln('before');
   for i := 1 to 10 do begin
                      readln(mergeSortInput[i]);
                  end;

   mergeSort(1, 10);
 
   writeln('after');
   for i := 1 to 10 do begin
                      write(mergeSortInput[i]);
                      write(' ');
                  end;
end.