def dfs(tickets, path, origin):
    path.append(origin)
    if not tickets:
        return True
    
    isDone = False
    for i, ticket in enumerate(tickets):
        if ticket[0] == origin:
            restTickets = tickets[:i] + tickets[i+1:]
            destination = ticket[1]
            isDone = dfs(restTickets, path, destination)
            if isDone:
                break
            else:
                path.pop()
    return isDone

def solution(tickets):
    tickets.sort()
    path = []
    dfs(tickets, path, 'ICN')
    return path