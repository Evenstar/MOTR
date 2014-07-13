function sequence=integral_l1(C,S)
len=1+3*(size(S,1)-2);
sequence=zeros(1,len);
pointer=1;
cur=1;
for i=1:size(S,1)-1
    if i==1
        sequence(cur)=norm(C(pointer:pointer+prod(S(1,:))-1),1);
        pointer=pointer+prod(S(1,:));
        cur=cur+1;
    else
        for j=1:3
            sequence(cur)=norm(C(pointer:pointer+prod(S(i,:))-1),1);
            pointer=pointer+prod(S(i,:));
            cur=cur+1;
        end
    end
    
end
end