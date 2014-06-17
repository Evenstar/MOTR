function tfnorm=tfnorm_1(im,dict,L)
dict=sortdict(dict);
st=tfdec2(im,dict,'sym',2);
tfnorm=0;
for i=1:L
    tfnorm=tfnorm+sum(sum(abs(st.coef{i})));
end
end