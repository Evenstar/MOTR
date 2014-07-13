function sequence=seq_wtf_l1(st)
cur=1;
sequence=[];
for i=1:length(st.coef)
    for j=1:length(st.coef{i})
        sequence(cur)=norm(st.coef{i}{j},1);
        cur=cur+1;
    end
end
end