function [result,small]=maxpooling(mat,stride,side)
result=zeros(size(mat));
small=zeros(floor(size(mat)/stride));
[m,n]=size(mat);
for i=1:stride:m-max(stride,side)+1
    for j=1:stride:n-max(stride,side)+1
        submtx=mat(i:i+side-1,j:j+side-1);
        [S,ind]=max(abs(submtx(:)));
        [a,b]=ind2sub(size(submtx),ind);
        result(i+a-1,j+b-1)=submtx(a,b);
        small(floor(i/stride)+1,floor(j/stride)+1)=S;
    end
end
end