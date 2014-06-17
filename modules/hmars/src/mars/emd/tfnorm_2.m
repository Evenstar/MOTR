function tfnorm=tfnorm_2(im,dict,L)
dict=sortdict(dict);
st=mtfdec2(im,dict,L,'sym');
tfnorm=0;
%low frequency
tfnorm=tfnorm+sum(sum(abs(st.coef{L}{1})));
st.coef{L}{1}=[];
for i=1:L
    tfnorm=tfnorm+sum(sum(abs(cell2mat(st.coef{i})))).*2^(i);
end
end