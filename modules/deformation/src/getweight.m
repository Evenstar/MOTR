function weight=getweight(C,S,a)
weight=zeros(size(C));
pointer=1;
for i=1:size(S,1)-1
    if i==1
    weight(pointer:pointer+prod(S(i,:))-1)=a^(1-i);
    pointer=pointer+prod(S(i,:));
    else
        for j=1:3
               weight(pointer:pointer+prod(S(i,:))-1)=a^(1-i);
               pointer=pointer+prod(S(i,:));
        end
    end
end
end